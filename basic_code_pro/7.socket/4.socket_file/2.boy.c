/*************************************************************************
	> File Name: 2.boy.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Jul 2021 03:57:16 PM CST
 ************************************************************************/

#include "common/head.h"

struct file_info {
    char name[50];
    ssize_t size;
};

int sockfd;

void close_sock(int signum) {
    send(sockfd, "Bye", 3, 0);
    close(sockfd);
    exit(0);
}

int main(int argc, char **argv) {
    struct file_info info;
    if (argc != 4) {
        fprintf(stderr, "Usage : %s ip port file!\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket_connect(argv[1], atoi(argv[2]))) < 0) {
        perror("socket_connect");
        exit(1);
    }

    FILE *fp = fopen(argv[3], "r");
    fseek(fp, 0, SEEK_END);
    info.size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    signal(SIGINT, close_sock);
    strcpy(info.name, argv[3]);
    send(sockfd, (void *)&info, sizeof(info), 0);

    while (1) {
        char buff[1024] = {0};
        ssize_t cnt = fread(buff, 1, 1024, fp);
        if (cnt == 0) {
            break;
        }
        send(sockfd, buff, strlen(buff), 0);
        printf("%s", buff);
    }
    fclose(fp);
    close(sockfd);
    return 0;
}
