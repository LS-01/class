/*************************************************************************
	> File Name: 1.server.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 01 Aug 2021 03:39:20 PM CST
 ************************************************************************/

#include "common/head.h"

int main(int argc, char **argv) {
    pid_t pid;
    int server_listen;

    if ((server_listen = socket_create(atoi(argv[1]))) < 0) {
        exit(1);
    }
    
    int sockfd;
    while (1) {
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            exit(1);
        }
        pid = fork();
        if (pid == 0) break;
        close(sockfd);
    }
    if (pid == 0) {
        close(server_listen);
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

    return 0;
}
