/*************************************************************************
	> File Name: 10.binary_search.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 07 Nov 2020 09:41:20 AM CST
 ************************************************************************/

#include <stdio.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

//1 3 5 7 9 11
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

//1111110000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000001111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int arr2[10] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    P(binary_search1(arr1, 10, 7));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 10));
    return 0;
}
