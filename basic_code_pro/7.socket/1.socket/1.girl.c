/*************************************************************************
	> File Name: 1.girl.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Jul 2021 03:20:26 PM CST
 ************************************************************************/

#include "common/head.h"

void Usage(const char *name) {
    fprintf(stderr, "Usage : %s -p port\n", name);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        Usage(argv[0]);
        exit(1);
    }
    int opt, port, sockfd;
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
    if ((sockfd = socket_create(port)) < 0) {
        perror("socker_create");
        exit(1);
    }
    while (1) {
        int new_fd, pid;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        if ((new_fd = accept(sockfd, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
        }
        printf("<Accept> : %s:%d!\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            while (1) {
                char buff[1024] = {0};
                size_t rsize = recv(new_fd, buff, sizeof(buff), 0);
                printf("<Recv %d> : %s\n", (int)rsize, buff);
                if (rsize <= 0) {
                    close(sockfd);
                    break;
                }
            }
            printf("<Bye> : A boy left!\n");
            exit(0);
        }
    }
    return 0;
}
