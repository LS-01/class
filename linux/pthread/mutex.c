/*************************************************************************
	> File Name: mutex.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 20 Oct 2020 08:37:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

int now;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *print() {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (now >= 1000) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        now++;
        printf("%d\n", now);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    int num = 5;
    pthread_t tid[num];
    for (int i = 0; i < num; i++) {
        pthread_create(&tid[i], NULL, print, NULL);
    }
    pthread_create(&tid[0], NULL, print, NULL);
    pthread_create(&tid[1], NULL, print, NULL);

    for (int i = 0; i < num; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
