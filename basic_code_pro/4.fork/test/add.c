/*************************************************************************
	> File Name: add.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 25 Jun 2021 03:55:55 PM CST
 ************************************************************************/

#include "common/head.h"

int main(int argc, char **argv) {
    int ins_cnt = 3;
    int start = 0;
    int end = 100;

    pid_t pid;
    for (int i = 0; i < ins_cnt; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            
        }
    }
    for (int i = 0; i < ins_cnt; i++) {
        wait(NULL);
    }
    return 0;
}
