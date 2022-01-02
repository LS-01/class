/*************************************************************************
	> File Name: 1.server.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 01 Aug 2021 03:39:20 PM CST
 ************************************************************************/

#include "common/head.h"

void *do_work(void *arg) {
    int sockfd;
    sockfd = *(int *)arg;

    while (1) {
        char buff[1024] = {0};
        int rsize = recv(sockfd, buff, sizeof(buff), 0);
        if (rsize <= 0) {
            break;
        }
        printf("%s", buff);
    }
    close(sockfd);
}

int main(int argc, char **argv) {
    int server_listen;

    if ((server_listen = socket_create(atoi(argv[1]))) < 0) {
        exit(1);
    }
    
    int sockfd[1024];
    pthread_t tid[1024];
    while (1) {
        //pthread_t tid; while中局部变量每次地址相同
        int fd;
        if ((fd = accept(server_listen, NULL, NULL)) < 0) {
            exit(1);
        }
        sockfd[fd] = fd;
        pthread_create(&tid[fd], NULL, do_work, (void *)&sockfd[fd]);
    }

    return 0;
}
