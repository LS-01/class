/*************************************************************************
	> File Name: 1.fork.test.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 11 Jun 2021 10:04:20 AM CST
 ************************************************************************/

#include "common/head.h"

int main() {
    pid_t pid;
    for (int i = 1; i < 11; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        sleep(1);
        if (pid == 0) {
            printf("i am %d p! <%d>--><%d>\n", i, getppid(), getpid());
            break;
        }
    }
    return 0;
}

