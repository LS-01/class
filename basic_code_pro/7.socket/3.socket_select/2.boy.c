/*************************************************************************
	> File Name: 2.boy.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Jul 2021 03:57:16 PM CST
 ************************************************************************/

#include "common/head.h"

int sockfd;

void close_sock(int signum) {
    send(sockfd, "Bye", 3, 0);
    close(sockfd);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port!\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket_connect(argv[1], atoi(argv[2]))) < 0) {
        perror("socket_connect");
        exit(1);
    }

    signal(SIGINT, close_sock);

    while (1) {
        char buff[1024] = {0};
        scanf("%[^\n]s", buff);
        getchar();
        if (strlen(buff)) {
            send(sockfd, buff, sizeof(buff), 0);
        }
    }
    return 0;
}
