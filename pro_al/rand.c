/*************************************************************************
	> File Name: rand.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 24 Dec 2020 10:10:58 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int op, val;
    #define MAX_OP 20 
    for (int i = 0; i < MAX_OP; i++) {
        switch (rand() % 5) {
            case 0: printf("0 %d\n", rand() % 15); break;
            case 1:
            case 2:
            case 3: printf("1 %d\n", rand() % 15); break;
            case 4: printf("2 %d\n", rand() % 15); break;
        }
    }
    #undef MAX_OP
    return 0;
}
