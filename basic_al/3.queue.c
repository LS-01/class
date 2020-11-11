/*************************************************************************
	> File Name: 3.queue.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 28 Oct 2020 07:22:37 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q-> tail = q->cnt = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int expand(Queue *q) {
    int extra_size = q->length;
    int *p;
    while (extra_size) {
        p = (int *)malloc(sizeof(int) * (q->length + extra_size));
        if (p) break;
        extra_size >>= 1;
    }
    if (p == NULL) return 0;
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        p[j] = q->data[(i + j) % q->length];
    }
    free(q->data);
    q->data = p;
    q->length += extra_size;
    q->head = 0;
    q->tail = q->cnt;
    return 1;
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->length) {
        if (!expand(q)) return 0;
        printf(GREEN("expand successfully ! Queue->size(%d)\n"), q->length);
    }
    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->length;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head++;
    if (q->head == q->length) q->head = 0;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->cnt; i++, j++) {
        j && printf(", ");
        printf("%d", q->data[i % q->length]);
    }
    printf("]\n");
    return;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                int v = front(q);
                printf("pop %d from the Queue = %d\n", v, pop(q));
            } break;
        }
        output(q), printf("\n");
    }
    #undef max_op
    clear(q);
    return 0;
}
