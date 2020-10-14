/*************************************************************************
	> File Name: test_1_prime.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 27 Sep 2020 06:18:13 PM CST
 ************************************************************************/

#include <stdio.h>

#define MAX_N 100

int prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) {
            continue;
        } else {
            prime[i] = i;
        }
        for (int j = i * i; j <= MAX_N; j += i) {
            if (prime[j]) {
                continue;
            }
            prime[j] = i;
        }
    }
    return;
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        printf("min %d = %d\n", i, prime[i]);
    }
    return 0;
}
