/*************************************************************************
	> File Name: test.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 08:23:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int age;
    char name[20] = {0};
    if (argc != 3) {
        fprintf(stderr, "Usage : %s name age!\n", argv[0]);
        exit(1);
    }
    strcpy(name, argv[1]);
    age = atoi(argv[2]);
    printf("%s is %d years old!\n", name, age);
    return 0;
}
