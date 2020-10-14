/*************************************************************************
	> File Name: test_6_program_structer.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 04:17:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b;
    //srand(7);
    srand(time(0));//second 1900-1-1
    printf("%ld\n", time(0));
    scanf("%d%d", &a, &b);
    if (a - b) {
        printf("not equal!\n");
    } else {
        printf("equal!\n");
    }
    a = 0, b = 2;
    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    if ((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);

    for (int i = 0; i < 10; i++) {
        //i && printf(" ");
        i == 0 || printf(" ");
        printf("%d", i);
    }
    printf("\n");

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        int val = rand() % 100;//0-99
        i && printf(" ");
        printf("%d", val);
        //val % 2 && cnt++;
        //val & 1 && cnt++;
        cnt += (val & 1);
    }
    printf("\nodd: %d\n", cnt);

    return 0;
}
