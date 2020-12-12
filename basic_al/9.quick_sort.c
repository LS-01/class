/*************************************************************************
	> File Name: 9.quick_sort.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 07 Nov 2020 03:04:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_n 20
#define swap(a, b) {\
    __typeof(a) __tmp = a;\
    a = b; b = __tmp;\
}

void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++, y--;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return;
}

int arr[max_n + 5];

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return;
}

void output(int *num, int n) {
    printf("arr = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("]\n");
    return;
}

int main() {
    srand(time(0));
    randint(arr, max_n);
    output(arr, max_n);
    quick_sort(arr, 0, max_n - 1);
    output(arr, max_n);
    return 0;
}
