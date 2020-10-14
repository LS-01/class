/*************************************************************************
	> File Name: test_3_printf.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 16 Sep 2020 08:21:25 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int main() {
    int n;
    scanf("%d", &n); //stdin
    printf("%04d\n", n);//stdout stderr 

    double d;
    scanf("%lf", &d);
    printf("%g\n", d);

    char str[1000] = {0}, buffer[1000] = {0}, *p = str, *q = buffer;
    sprintf(str, "%d.%d.%d.%d", 192, 168, 0, 1); //192.168.0.1
    printf("%s\n", str);

    if (n & 1) {
        sprintf(q, "(%s)", p);
        swap(p, q);
    }
    if (n & 2) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 4) {
        sprintf(q, "{%s}", p);
        swap(p, q)
    }
    printf("%s\n", p);

    FILE *fout = fopen("output", "w");
    fprintf(fout, "str = %s\n", p);
    fclose(fout);
    fprintf(stdout, "stdout = %s\n", p);
    fprintf(stderr, "stderr = %s\n", p);
    return 0;
}
