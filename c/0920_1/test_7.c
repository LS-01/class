/*************************************************************************
	> File Name: test_7.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 06:03:36 PM CST
 ************************************************************************/

#include <stdio.h>

int is_reverse(int n, int base) {
    if (n < 0) {
        return 0;
    }
    int sum = 0, x = n;
    while (x) {
        sum = sum * base + x % base;
        x /= base;
    }
    return sum == n;
}

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, x, digit = 0;
    scanf("%d", &n);
    x = n;
    do {
        digit += 1;
        n /= 10;
    } while (n);
    printf("%d has %d digits!\n", x, digit);
    printf("%s\n", is_reverse(x, 10) ? "YES" : "NO");
    printf("%d is %sa prime\n", x, is_prime(x) ? "" : "not ");
    return 0;
}
