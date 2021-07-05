/*************************************************************************
	> File Name: dup_test.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 02 Jul 2021 03:08:10 PM CST
 ************************************************************************/

#include "common/head.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("give me a file name\n");
        exit(1);
    }
    int fd = open(argv[1], O_CREAT | O_RDWR, 0777);
    printf("fd = %d\n", fd);
    dup2(fd, STDOUT_FILENO);
    printf("fd = %d\n", fd);
    close(fd);
    sleep(5);
    return 0;
}
