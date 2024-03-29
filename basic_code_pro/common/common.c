/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: 2021年04月15日 星期四 18时54分19秒
 ************************************************************************/

#include "head.h"

int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag |= O_NONBLOCK;
    if ((fcntl(fd, F_SETFL, flag)) < 0) {
        return -1;
    }
    return 0;
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag &= ~O_NONBLOCK;
    if ((fcntl(fd, F_SETFL, flag)) < 0) {
        return -1;
    }
    return 0;
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
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        return -1;
    }
    return sockfd;
}

int socket_connect(const char *ip, int port) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        return -1;  
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()");
        return -1;
    }
    return sockfd;
}
