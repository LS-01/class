/*************************************************************************
	> File Name: 1.pthread.c
	> Author: ls
	> Mail: 
	> Created Time: Mon 05 Jul 2021 03:03:22 PM CST
 ************************************************************************/

#include "common/head.h"

struct Arg {
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Arg argin;
    argin = *(struct Arg *)arg;
    printf("%s and %d %p\n", argin.name, argin.age, &arg);
}

int main() {
    pthread_t thread;
    struct Arg arg;
    memset(&arg, 0, sizeof(arg));
    strcpy(arg.name, "ls");
    for (int i = 1; i <= 100; i++) {
        arg.age = i;
        pthread_create(&thread, NULL, print, (void *)&arg);
    }
    usleep(1000);
    return 0;
}
