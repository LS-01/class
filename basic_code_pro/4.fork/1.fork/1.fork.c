/*************************************************************************
	> File Name: 1.fork.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 11 Jun 2021 09:41:03 AM CST
 ************************************************************************/

#include "common/head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }

    //zsh(echo $$)-->a.out-->childp
    if (pid) {
        printf("In Parent Process! <%d>--><%d>--><%d>\n", getppid(), getpid(), pid);
    } else {
        printf("In Child Process! <%d>--><%d>\n", getppid(), getpid());
    }
    return 0;
}

