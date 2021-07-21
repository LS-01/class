/*************************************************************************
	> File Name: 2.client.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 20 Jul 2021 10:47:20 AM CST
 ************************************************************************/

#include "common/head.h"

struct Packet {
    char filename[50];
    ssize_t size;
    char body[1024];
};

int send_file(const char *file, int sockfd) {
    FILE *fp;
    char *p;
    struct Packet packet;
    memset(&packet, 0, sizeof(packet));
    //strcpy(packet.filename, file);
    strcpy(packet.filename, (p = strrchr(file, '/')) ? p + 1 : file);
    if ((fp = fopen(file, "r")) == NULL) {
        perror("fopen");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    packet.size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    while (1) {
        ssize_t nread = fread(packet.body, 1, sizeof(packet.body), fp);
        if (nread <= 0) {
            break;
        }
        //buff
        send(sockfd, (void *)&packet, sizeof(packet), 0);
        memset(packet.body, 0, sizeof(packet.body));
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage : %s ip port file!\n", argv[0]);
        exit(1);
    }
    int sockfd, port, ack;
    char ip[20] = {0}, file[50] = {0};
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    strcpy(file, argv[3]);

    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect");
        exit(1);
    }
    send(sockfd, "ls", sizeof("ls"), 0);
    int rsize = recv(sockfd, (void *)&ack, sizeof(int), 0);
    if (rsize <= 0 || ack != 1) {
        close(sockfd);
        exit(1);
    }
    printf("Waiting for data transfer!\n");

    send_file(file, sockfd);

    close(sockfd);
    return 0;
}
