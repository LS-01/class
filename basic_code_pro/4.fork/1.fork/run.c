/*************************************************************************
	> File Name: run.c
	> Author: ls
	> Mail: 
	> Created Time: Mon 21 Jun 2021 09:46:17 AM CST
 ************************************************************************/

#include "common/head.h"

int exist(char* file) {
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL) {
        return 0;
    } else {
        fclose(fp);
        return 1;
    }
}

int main(int argc, char** argv) {
    char* filename = argv[1];
    pid_t pid;
    int status;
    while (!exist(filename)) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            execlp("/usr/bin/vim", "vim", filename, NULL);
        } else {
            wait(&status);
        }
    }
    
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("/usr/bin/gcc", "gcc", filename, NULL);
    } else {
        wait(&status);
        if (status == 0) {
            if ((pid = fork()) < 0) {
                perror("fork()");
                exit(1);
            }
            if (pid == 0) {
                execlp("./a.out", "a.out", NULL);
            } else {
                wait(&status);
            }
        }
    }
    return 0;
}

