/*************************************************************************
	> File Name: 1.pthread.c
	> Author: ls
	> Mail: 
	> Created Time: Mon 05 Jul 2021 03:03:22 PM CST
 ************************************************************************/

#include "common/head.h"
#define INS 100

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
    pthread_t *tid = calloc(INS + 5, sizeof(pthread_t));
    struct Arg *arg = calloc(INS + 5, sizeof(struct Arg));
    for (int i = 1; i <= INS; i++) {
        strcpy(arg[i].name, "ls");
        arg[i].age = i;
        pthread_create(&tid[i], NULL, print, (void *)&arg[i]);
    }
    for (int i = 1; i <= INS; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
