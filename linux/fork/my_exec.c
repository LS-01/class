/*************************************************************************
	> File Name: my_exec.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 04:55:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

//try system
int main(int argc, char *argv[]) {
    int opt;
    int m_flag = 0;
    char msg[512] = {0};
    while ((opt = getopt(argc, argv, "m:")) != -1) {
        switch (opt) {
            case 'm':
                //printf("have m!\n");
                m_flag = 1;
                strcpy(msg, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -m msg\n", argv[0]);
                exit(1);
                break;
        }
    }
    if (m_flag == 1) {
        printf("%s\n", msg);
        return 0;
    }

    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    
    if (pid == 0) {
        execlp("vim", "vim", "tmp.txt", NULL); 
    } else {
        wait(NULL);
        pid_t pid1;
        if ((pid1 = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid1 == 0) {
            execlp("cat", "cat", "tmp.txt", NULL);
        } else {
            wait(NULL);
            execlp("rm", "rm", "tmp.txt", NULL);
        }
    }
    
    return 0;
}
