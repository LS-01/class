/*************************************************************************
	> File Name: 1.epoll_server.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 07 Aug 2021 04:20:10 PM CST
 ************************************************************************/
//2 problems 
//1:name
//2:not response
#include "common/head.h"
#include "common/color.h"

#define MAXUSER 1024
#define MAXEVENT 10

struct NUser {
    char name[50];
    int fd;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usgae : %s port!\n", argv[0]);
        exit(1);
    }

    int epollfd, server_listen, sockfd;
    struct epoll_event ev, events[MAXEVENT];
    struct NUser users[MAXUSER];
    memset(&users, 0, MAXUSER * sizeof(struct NUser));

    if ((epollfd = epoll_create(1)) < 0) {
        perror("epoll_create");
        exit(1);
    }
    if ((server_listen = socket_create(atoi(argv[1]))) < 0) {
        perror("socket_create");
        exit(1);
    }

    strcpy(users[server_listen].name, "Listener");
    users[server_listen].fd = server_listen;

    ev.events = EPOLLIN;
    ev.data.ptr = &users[server_listen];

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, server_listen, &ev) < 0) {
        perror("epoll_ctl");
        exit(1);
    }

    while (1) {
        int nfds;
        if ((nfds = epoll_wait(epollfd, events, MAXEVENT, -1)) < 0) {
            perror("epoll_wait");
            exit(1);
        }
        for (int i = 0; i < nfds; i++) {
            struct NUser *user = (struct NUser *)events[i].data.ptr;
            if (user->fd == server_listen) {
                DBG(GREEN"<New coming>...\n"NONE);
                if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
                    perror("accept");
                    exit(1);
                }
                if (sockfd > MAXUSER) {
                    fprintf(stderr, RED"Too Many clients!\n"NONE);
                    continue;
                }
                users[sockfd].fd = sockfd;
                ev.data.ptr = &users[sockfd];
                ev.events = EPOLLIN | EPOLLET;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0) {
                    perror("epoll_ctl");
                    exit(1);
                }
            } else {
                char buff[1024] = {0};
                if (events[i].events & (EPOLLIN | EPOLLERR | EPOLLHUP)) {
                    if (!strlen(user->name)) {
                        if (recv(user->fd, user->name, sizeof(user->name), 0) <= 0) {
                            close(user->fd);
                            user->fd = -1;
                            epoll_ctl(epollfd, EPOLL_CTL_DEL, user->fd, NULL);
                        }
                        user->name[strlen(user->name) - 2] = '\0';//-2 why not -1?
                        DBG(GREEN"<Login>"NONE" : %s!\n", user->name);
                        continue;
                    }
                    int ret = recv(user->fd, buff, sizeof(buff), 0);
                    if (ret <= 0) {
                        close(user->fd);
                        memset(user->name, 0, sizeof(user->name));
                        epoll_ctl(epollfd, EPOLL_CTL_DEL, user->fd, NULL);
                        continue;
                    }
                    printf(BLUE"%s"NONE" : %s", user->name, buff);
                }
            }
        }
    }

    return 0;
}
