/*************************************************************************
	> File Name: 2.multi_thread_add.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 06 Jul 2021 01:42:50 PM CST
 ************************************************************************/

#include "common/head.h"
#define INS 50
#define MAX 100

int now;
int sum;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *work(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (now > MAX) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        sum += now;
        usleep(150);
        now++;
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t *thread;
    thread = calloc(INS, sizeof(pthread_t));
    for (int i = 0; i < INS; i++) {
        pthread_create(&thread[i], NULL, work, NULL);
    }
    for (int i = 0; i < INS; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("now = %d sum = %d\n", now, sum);
    return 0;
}
