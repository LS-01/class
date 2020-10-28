/*************************************************************************
	> File Name: test.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 16 Oct 2020 06:27:02 PM CST
 ************************************************************************/
#include <haizei/test.h>
#include <haizei/linklist.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

Function func_head, *func_tail = &func_head;
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
        Function *func = Head(p, Function, p);
        printf(GREEN("[====RUN====]") RED_HL("%s") "\n", func->str);
        haizei_test_info.total = 0, haizei_test_info.success = 0;
        func->func();
        double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]") "total : %d  success : %d\n", haizei_test_info.total, haizei_test_info.success);
    }
    return 0;
}

void add_function(TestFunc func, const char *str) {
    Function *temp = (Function *)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
}
