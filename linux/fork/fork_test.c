/*************************************************************************
	> File Name: fork_test.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 02:33:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int x;
    for (int i = 1; i <= 100; i++) {
        x = i;
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            break;
        }
    }
    if (pid == 0) {
        printf("I'm %dth child!\n", x);
        //sleep(100);
    } else {
        //sleep(200);
        for (int i = 1; i <= 100; i++) {
            int wstatus;
            pid_t rpid = wait(&wstatus);
            printf("Child %d returns with code %d\n", rpid, wstatus);
        }
        int tmp = wait(NULL);
        printf("%d\n", tmp);
    }
    return 0;
}
