/*************************************************************************
	> File Name: haizei/test.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 16 Oct 2020 06:27:02 PM CST
 ************************************************************************/
#include <haizei/test.h>
#include <string.h>
#include <stdio.h>

Function func_arr[100];
int func_cnt = 0;

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf("Test run : %s\n", func_arr[i].str);
        func_arr[i].func();
        printf("Test end.\n");
    }
    return 0;
}

void add_function(TestFunc func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
}
