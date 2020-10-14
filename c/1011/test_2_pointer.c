/*************************************************************************
	> File Name: test_2_pointer.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 11 Oct 2020 04:34:22 PM CST
 ************************************************************************/

#include <stdio.h>
#define offset(T, a) (long)(&(((T*)(NULL))->a))

struct Data {
    int a;
    double b;
    char c;
};

int main() {
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%p - %p\n", &num1, &num2);
    printf("%s\n", (char *)(&num1));
    printf("%p - %p\n", &num1, &num2);
    printf("%s\n", (char *)(&num2));
    printf("%p - %p\n", &num1, &num2);
//    printf("%s\n", (char *)(&num2 + 1));
    
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    return 0;
}
