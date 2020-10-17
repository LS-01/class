/*************************************************************************
	> File Name: my_run.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 07:24:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage : %s filename.c arg...\n", argv[0]);
        exit(1);
    }

    char filename[512] = {0};
    char f_type[512] = {0};
    char b_name[512] = {0};
    char g_cmd[512] = {0};

    strcpy(filename, argv[1]);

    char *sub;
    if ((sub = strrchr(filename, '.')) == NULL) {
        fprintf(stderr, "Filename is not supported!\n");
        exit(2);
    }

    strncpy(b_name, filename, sub - filename);
    strcpy(f_type, sub);

    if (!strcmp(f_type, ".c")) {
        strcpy(g_cmd, "gcc");
    } else if (!strcmp(f_type, ".cpp")) {
        strcpy(g_cmd, "g++");
    } else {
        fprintf(stderr, "File type is not supported!\n");
        exit(2);
    }

    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("vim", "vim", filename, NULL); 
    }
    wait(NULL);
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp(g_cmd, g_cmd, filename, "-o", b_name, NULL);
    }
    int wstatus;
    wait(&wstatus);
    if (wstatus == 0) {
        printf("OK!");
        char tmp_name[512] = {0};
        sprintf(tmp_name, "./%s", b_name);
        execv(tmp_name, argv + 1);
    } else {
        printf("Failed!");
        exit(3);
    }

    return 0;
}
