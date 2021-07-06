/*************************************************************************
	> File Name: multi_thread_add.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 06 Jul 2021 01:28:04 PM CST
 ************************************************************************/

#include "common/head.h"
#define INS 50

struct NUM {
    int cnt;
    int sum;
    pthread_mutex_t mutex;
};

void *add(void *v_num) {
    struct NUM *num = (struct NUM *)v_num;
    printf("%p\n", num);
    while (1) {
        pthread_mutex_lock(&(num->mutex));
        if (num->cnt >= 100) {
            pthread_mutex_unlock(&(num->mutex));
            return NULL;
        }
        usleep(150);
        num->cnt++;
        usleep(150);
        num->sum += num->cnt;
        printf("cnt = %d sum = %d\n", num->cnt, num->sum);
        pthread_mutex_unlock(&(num->mutex));
    }
}

int main() {
    struct NUM num;
    num.cnt = 0;
    num.sum = 0;
    pthread_mutex_init(&(num.mutex), NULL);
    pthread_t *pids;
    pids = calloc(INS, sizeof(pthread_t));
    for (int i = 0; i < INS; i++) {
        pthread_create(&pids[i], NULL, *add, (void *)&num);
    }
    for (int i = 0; i < INS; i++) {
        pthread_join(pids[i], NULL);
    }
    printf("%d\n", num.sum);
    return 0;
}
