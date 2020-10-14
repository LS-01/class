/*************************************************************************
	> File Name: test_4_newton.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 27 Sep 2020 09:00:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double F(double x, double n) {
    return x * x - n;
}

double f(double x) {
    return 2 * x;
}

double newton(double (*F)(double, double), double (*f)(double), double n) {
    double x = n / 2.0;
    #define EPSL 1e-6
    while (fabs(F(x, n)) > EPSL) {
        x -= F(x, n) / f(x);
    }
    #undef EPSL
    return x;
}

double my_sqrt(double n) {
    return newton(F, f, n);
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        printf("%g\n", my_sqrt(n));
    }
    return 0;
}
