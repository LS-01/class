/*************************************************************************
	> File Name: test_3.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 08:43:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t Triangle(int64_t n) {
    return n * (n + 1) / 2;
}

int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

int64_t binary_search(int64_t (*func)(int64_t), int64_t x) {
    int64_t head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) {
            return mid;
        } else if (func(mid) < x) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = 143;
    while (1) {
        n++;
        int val = Hexagonal(n);
        //if (binary_search(Triangle, val) == -1) {
        //    continue;
        //}
        if (binary_search(Pentagonal, val) == -1) {
            continue;
        }
        break;
    }
    printf("%" PRId64 "\n", Hexagonal(n));
    return 0;
}
