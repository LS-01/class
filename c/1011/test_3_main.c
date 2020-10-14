/*************************************************************************
	> File Name: test_3_main.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 11 Oct 2020 06:39:10 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ppchar char *
typedef char * pchar;

void output(int argc, char *argv[], char **env) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        if (!strncmp(env[i], "USER=", 5)) {
            if (!strcmp(env[i] + 5, "ls-")) {
                printf("welcome!\n");
            } else {
                printf("who are you?\n");
                exit(0);
            }
        }
        printf("env[%d] = %s\n", i, env[i]);
    }
    return;
}

int main(int argc, char *argv[], char **env) {
    pchar p1, p2;
    ppchar p3, p4;
    printf("p1 = %lu, p2 = %lu\n", sizeof(p1), sizeof(p2));
    printf("p3 = %lu, p4 = %lu\n", sizeof(p3), sizeof(p4));
    
    output(argc, argv, env);
    return 0;
}
