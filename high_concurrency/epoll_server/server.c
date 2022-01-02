/*************************************************************************
	> File Name: server.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Jul 2021 03:20:26 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

#define MAX_EVENTS 20
#define MAX_CONNECT 2000
#define MAX_CONTENT 4096

typedef struct CONNECT {
    char text[MAX_CONTENT + 5];
    int ind;
} CONNECT;

void transform_and_send(int fd, char *text, int len, CONNECT *connects) {
    char *content = connects[fd].text;
    int *ind = &(connects[fd].ind);
    int dis = 32;
    for (int i = 0; i < len; i++) {
        if (text[i] == '\n') {
            content[(*ind)++] = text[i];
            send(fd, content, strlen(content), 0);
            memset(content, '\0', (MAX_CONTENT + 5) * sizeof(char));
            *ind = 0;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            content[(*ind)++] = text[i] - dis;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            content[(*ind)++] = text[i] + dis;
        } else {
            content[(*ind)++] = text[i];
        }
    }
}

int socket_create(int port) {
    int sockfd;
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        return -1;
    }
    return sockfd;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s -p port\n", argv[0]);
        exit(1);
    }
    int opt, port, sockfd;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -p port\n", argv[0]);
                exit(1);
        }
    }

    struct epoll_event ev, events[MAX_EVENTS];
    CONNECT *connects = (CONNECT *)calloc(MAX_CONNECT + 5, sizeof(CONNECT));
    int listen_sock, conn_sock, nfds, epollfd;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    if ((listen_sock = socket_create(port)) < 0) {
        perror("socker_create");
        exit(1);
    }

    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);       
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);                                                                             
    }

    for (;;) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listen_sock) {
                conn_sock = accept(listen_sock,(struct sockaddr *) &addr, &addrlen);
                if (conn_sock == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                struct epoll_event new_ev;
                new_ev.events = EPOLLIN | EPOLLET;
                new_ev.data.fd = conn_sock;
                if (conn_sock >= MAX_CONNECT) {
                    perror("Too many connects!\n");
                    exit(EXIT_FAILURE);
                }
                memset(connects[conn_sock].text, '\0', (MAX_CONTENT + 5) * sizeof(char));
                connects[conn_sock].ind = 0;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &new_ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                int new_fd = events[n].data.fd;
                char buff[1024 * 4 + 5] = {0};
                size_t rsize = recv(new_fd, buff, sizeof(buff), 0);
                if (rsize <= 0) {
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, new_fd, &events[n]);
                    close(new_fd);
                } else {  
                    transform_and_send(new_fd, buff, (int)rsize, connects);
                }
            }
        }
    }
    return 0;
}
