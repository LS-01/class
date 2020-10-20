/*************************************************************************
	> File Name: pthread.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 20 Oct 2020 08:06:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

struct MyArg {
    char name[20];
    int age;
};

void *print(void *arg) {
    //sleep(2);
    struct MyArg myarg = *(struct MyArg *)arg;
    printf("%s is %d years old!\n", myarg.name, myarg.age);
    sleep(2);
    //pthread_exit(NULL);
    printf("Thread killed!\n");
}

int main() {
    pthread_t tid;
    while (1) {
        struct MyArg myarg;
        printf("Please input:!\n");
        scanf("%d", &myarg.age);
        strcpy(myarg.name, "ls");
        pthread_create(&tid, NULL, print, (void *)&myarg);
        pthread_detach(tid);
        //pthread_cancel(tid);
    }
    //usleep(1000);
    //pthread_join(tid, NULL);
    sleep(30);
    return 0;
}
