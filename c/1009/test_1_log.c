/*************************************************************************
	> File Name: test_1_log.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 09 Oct 2020 06:15:46 PM CST
 ************************************************************************/

#include <stdio.h>
#ifdef DEBUG
#define log(frm, argc...) {\
    printf("[%s : %d] ", __func__, __LINE__);\
    printf(frm, ##argc);\
    printf("\n");\
}
#else
#define log(frm, argc...)
#endif

#define contact(a, b) a##b

void func(int a) {
    a += 1;
    log("%d", a);
    return;
}

int main() {
    int a = 123, abcdef = 0;
    printf("[%s : %d] %d\n", __func__, __LINE__, a);
    func(a);
    log("%d", a);
    log("hello world");
    contact(abc, def) = 24;
    log("%d", abcdef);
    return 0;
}
