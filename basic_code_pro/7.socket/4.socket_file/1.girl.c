/*************************************************************************
	> File Name: 1.girl.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Jul 2021 03:20:26 PM CST
 ************************************************************************/

#include "common/head.h"
#define MAX_USER 100
struct file_info {
    char name[50];
    ssize_t size;
};

void Usage(const char *name) {
    fprintf(stderr, "Usage : %s -p port\n", name);
}

void *worker(void *arg) {
    int fd;
    fd = *(int *)arg;
    struct file_info info;
    recv(fd, (void *)&info, sizeof(info), 0);
    printf("file_name = %s\n", info.name);
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
    int fd[MAX_USER + 5];
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
        int new_fd;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        if ((new_fd = accept(sockfd, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
        }
        if (new_fd >= MAX_USER) {
            close(new_fd);
            printf("Too Many User!\n");
            break;
        }
        fd[new_fd] = new_fd;
        printf("<Accept> %s:%d!\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        pthread_create(&tid[new_fd], NULL, worker, (void *)&fd[new_fd]);
    }
    return 0;
}
