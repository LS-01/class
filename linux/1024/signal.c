/*************************************************************************
	> File Name: signal.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 24 Oct 2020 07:45:39 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void print(int signum) {
    printf("Bye!\n");
}

int main() {
    signal(SIGINT, print);

    while (1) {
        sleep(10);
    }

    return 0;
}
