/*************************************************************************
	> File Name: test_8.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 07:18:02 PM CST
 ************************************************************************/

#include <stdio.h>

int kx(int k, int b, int x) {
    return k * x + b;
}

int main() {
    int k, b;
    scanf("%d%d", &k, &b);
    for (int i = 1; i < 100; i++) {
        printf("%d %d\n", i, kx(k, b, i));
    }
    return 0;
}
