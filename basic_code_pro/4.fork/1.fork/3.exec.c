/*************************************************************************
	> File Name: 3.exec.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Jun 2021 11:31:51 PM CST
 ************************************************************************/

#include "common/head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("/bin/cat", "cat", "/etc/hosts", NULL);
        printf("haha!\n");
        fflush(stdout);
    } else {
        int status;
        wait(&status);
        printf("status = %d\n", status);
    }
    return 0;
}

