/*************************************************************************
	> File Name: test_2_prime.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 26 Sep 2020 10:54:50 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100
int prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) {
            continue;
        }
        prime[++prime[0]] = i;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    return;
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
