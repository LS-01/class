/*************************************************************************
	> File Name: exec_test.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 04:55:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }

    if (pid == 0) {
        printf("I'm Child!\nI'm doing a great job now!\n");
        execlp("cat", "cat", "exec.c", NULL);
        printf("I'm dead!\n");
    } else {
        printf("I'm Father!\n");
        wait(NULL);
    }
    return 0;
}
