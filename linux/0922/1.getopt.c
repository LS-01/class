/*************************************************************************
	> File Name: 1.getopt.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 24 Sep 2020 12:37:27 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char c;
    char name[20] = {'0'};
    int age = 0;
    char sex[5] = {0};
    char title[51] = {0};
    while ((c = getopt(argc, argv, "n:a:s:t::")) != -1) {
        switch (c) {
            case 'n':
                strcpy(name, optarg);
                break;
            case 'a':
                age = atoi(optarg);
                break;
            case 's':
                strcpy(sex, optarg);
                break;
            case 't':
                optarg == 0 || strcpy(title, optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -n name -s sex -a age -t title!\n", argv[0]);
                exit(1);
        }
    }

    printf("%s is %d years old, %s, with title %s!\n", name, age, sex, title);
    return 0;
}
