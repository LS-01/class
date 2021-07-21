/*************************************************************************
	> File Name: 1.girl.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Jul 2021 03:20:26 PM CST
 ************************************************************************/

#include "common/head.h"
#define MAX_USER 100
//添加超时断开功能(select自带)

void Usage(const char *name) {
    fprintf(stderr, "Usage : %s -p port\n", name);
}

void *worker(void *arg) {
    int fd;
    fd = *(int *)arg;
    while (1) {
        char buff[1024] = {0};
        size_t rsize = recv(fd, buff, sizeof(buff), 0);
        printf("<Recv %d> : %s\n", (int)rsize, buff);
        if (rsize <= 0) {
            close(fd);
            break;
        } else {
            send(fd, buff, strlen(buff), 0);
        }
    }
    printf("<Bye> : A boy left!\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[0]);
        exit(1);
    }
    pthread_t tid[MAX_USER + 5];
    int fd[MAX_USER + 5] = {0};
    int opt, port, server_listen, maxfd = 0;
    while ((opt = getopt(argc, argv, "p:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                Usage(argv[0]);
                exit(1);
        }
    }
    if ((server_listen = socket_create(port)) < 0) {
        perror("socker_create");
        exit(1);
    }
    fd_set rfds;
    maxfd = server_listen;
    fd[server_listen] = server_listen;

    while (1) {
        FD_ZERO(&rfds);
        for (int i = 0; i < MAX_USER; i++) {
            if (fd[i] > 0) {
                FD_SET(fd[i], &rfds);
            }
        }
        int rnum = select(maxfd + 1, &rfds, NULL, NULL, NULL);
        if (rnum < 0) {
            perror("select()");
            exit(1);
        }
        if (FD_ISSET(server_listen, &rfds)) {
            int new_fd;
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            if ((new_fd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
                perror("accept");
                exit(1);
            }
            if (new_fd >= MAX_USER) {
                close(new_fd);
                printf("Too Many User!\n");
                break;
            }
            if (maxfd < new_fd) {
                maxfd = new_fd;
            }
            fd[new_fd] = new_fd;
            printf("<Accept> %s:%d!\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        }
        for (int i = 0; i < MAX_USER; i++) {
            if (fd[i] == server_listen) {
                continue;
            }
            if (fd[i] > 0 && FD_ISSET(fd[i], &rfds)) {
                char buff[1024] = {0};
                int rsize = recv(fd[i], buff, sizeof(buff), 0);
                if (rsize <= 0) {
                    close(fd[i]);
                    fd[i] = 0;
                } else {
                    send(fd[i], buff, strlen(buff), 0);
                }
            }
        }
    }
    return 0;
}
