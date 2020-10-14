/*************************************************************************
	> File Name: test_3_binary_search.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 27 Sep 2020 08:00:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
//1 2 3 4 5 6 7 8 9 10
//1 4 9 16 25 36 49 64 81 100

double func(double x) {
    return x * x;
}

double binary_search(double (*arr)(double), double x) {
    double head = 0, tail = x, mid = 0;
    if (x < 1.0) tail = 1.0;
    #define ESPL 1e-7
    while (tail - head > ESPL) {
        mid = (head + tail) / 2.0;
        if (arr(mid) < x) head = mid;
        else tail = mid;
    }
    #undef ESPL
    return mid;
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        double x = binary_search(func, n);
        printf("%g * %g = %g\n", x, x, n);
    }
    return 0;
}
