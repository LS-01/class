/*************************************************************************
	> File Name: 1.vector.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 28 Oct 2020 10:46:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Vector {
    int *data;
    int length, size;
} Vec;

Vec *init(int n) {
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(Vec *v) {
    int extra_size = v->size;
    int *p;
    while (extra_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extra_size));
        if (p) break;
        extra_size /= 2;
    }
    if (extra_size == 0) return 0;
    v->data = p;
    v->size += extra_size;
    return 1;
}

void clear(Vec *v) {
    if (v == NULL) return;
    free(v->data);
    free(v);
    return;
}

int insert(Vec *v, int val, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size) {
        if (!expand(v)) return 0;
        printf(GREEN("success to expand! the vector size is %d\n"), v->size);
    }
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vec *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output(Vec *v) {
    if (v == NULL) return;
    printf("Vector : [");
    for (int i = 0; i < v->length; i++) {
        i && printf(", ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Vec *v = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) - 1;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("Insert %d at %d to Vector = %d\n", val, ind, insert(v, val, ind));
            } break;
            case 3: {
                printf("erase a item at %d from Vector = %d\n", ind, erase(v, ind));
            }
        }
        output(v), printf("\n");
    }
    #undef max_op
    clear(v);
    return 0;
}
