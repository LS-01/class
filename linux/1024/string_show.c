/*************************************************************************
	> File Name: string_show.c
	> Author: ls
	> Mail: 
	> Created Time: Mon 26 Oct 2020 08:50:18 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char a[100] = "abcdefg";
    printf("%5s1\n", a);
    printf("%15s1\n", a);
    printf("%.2s1\n", a);
    printf("%10.2s1\n", a);
    return 0;
}
