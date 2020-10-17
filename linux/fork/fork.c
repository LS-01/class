/*************************************************************************
	> File Name: fork.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 02:33:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void create_process() {
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
        sleep(100);
    } else {
        sleep(200);
    }
}

int main() {
/*    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        printf("I'm child!\n");
    } else {
        //sleep(1);
        usleep(100);
        printf("I'm parent!\n");
    }
*/
    create_process();
    return 0;
}
