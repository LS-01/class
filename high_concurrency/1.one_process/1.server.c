/*************************************************************************
	> File Name: 1.server.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 31 Jul 2021 02:42:38 PM CST
 ************************************************************************/

#include "common/head.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage");
        exit(1);
    }
    int server_listen, sockfd;
    if ((server_listen = socket_create(atoi(argv[1]))) < 0) {
        perror("socket_create");
        exit(1);
    }
    int max_fd = 0;
    struct timeval tv;
    int client[1024] = {0};
    tv.tv_sec = 0;
    tv.tv_usec = 1000000;
    fd_set rfds, wfds, efds;
    FD_ZERO(&rfds);
    FD_SET(server_listen, &rfds);
    max_fd = server_listen;

    while (1) {
        FD_ZERO(&rfds);
        FD_SET(server_listen, &rfds);
        for (int i = 0; i <= max_fd; i++) {
            if (client[i] != 0) {
                FD_SET(client[i], &rfds);
            }
        }
        //int ret = select(max_fd + 1, &rfds, &wfds, &efds, &tv);
        int ret = select(max_fd + 1, &rfds, NULL, NULL, NULL);
        if (ret) {
            DBG("Someone is ready!\n");
            if (FD_ISSET(server_listen, &rfds)) {
                DBG("Someone is coming!\n");
                if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
                    perror("accept");
                    exit(1);
                }
                if (max_fd < sockfd) max_fd = sockfd;
                client[sockfd] = sockfd;
                make_nonblock(sockfd);
                ret--;
                if (max_fd == 1024) {
                    close(sockfd);
                    client[1024] = 0;
                }
            }
            for (int i = 0; i <= max_fd; i++) {
                if (!ret) break;
                if (client[i] && FD_ISSET(client[i], &rfds)) {
                    ret--;
                    char buff[1024] = {0};
                    int rsize = recv(client[i], buff, sizeof(buff), 0);
                    if (rsize <= 0) {
                        close(client[i]);
                        client[i] = 0;
                        continue;
                    }
                    printf("%s", buff);
                }
            }
        }
    }

    return 0;
}
