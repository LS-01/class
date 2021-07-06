/*************************************************************************
	> File Name: thread_pool.h
	> Author: ls
	> Mail: 
	> Created Time: Tue 06 Jul 2021 02:52:55 PM CST
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
struct task_queue {
    int size;
    int total;
    int head;
    int tail;
    void **data;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

void task_queue_init(struct task_queue *taskQueue, int size);
void task_queue_push(struct task_queue *taskQueue, char *str);
char *task_queue_pop(struct task_queue *taskQueue);
#endif
