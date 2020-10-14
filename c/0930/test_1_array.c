/*************************************************************************
	> File Name: test_1_array.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 30 Sep 2020 06:12:00 PM CST
 ************************************************************************/

#include <stdio.h>

void func(int *a) { //形参
    *a = 123;
    printf("sizeof(*a) = %lu\n", sizeof(a));
    printf("a = %p, a + 1 = %p\n", a, a + 1);
    //*(a + 0) = 123;
    //a[0] = 123;
    return;
}

void f1(int n, int a[n]) {
    a[0] = 1234;
}

void f2(int (*a)[200]) {
    a[0][0] = 234;
}

int main() {
    int arr[100];
    printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);
    printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);
    char *p = (char *)arr;
    printf("p = %p, p + 1 = %p\n", p, p + 1);
    int n = 0;
    func(arr); //实参
    printf("sizeof(arr) = %lu\n", sizeof(arr));
    printf("%d\n", n);
    for (int i = 0; i < 10; i++) {
        //scanf("%d", &arr[i]);
        //scanf("%d", arr + i);
    }
    f1(100, arr);
    printf("%d\n", arr[0]);
    int arr_2[100][200];
    f2(arr_2);
    return 0;
}
