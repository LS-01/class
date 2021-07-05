/*************************************************************************
	> File Name: 2.10child.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Jun 2021 02:52:10 PM CST
 ************************************************************************/

#include "common/head.h"

int main() {
    pid_t pid;
    int i = 1;
    for (; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            break;
        }
    }
    if (pid == 0) {
        printf("I'm the %dth Child Process!\n", i);
    } else {
        for (int j = 0; j < 10; j++) {
            wait(NULL);
        }
        printf("I'm Parent Process!\n");
    }
    return 0;
}

