/*************************************************************************
	> File Name: 5.pwd.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 16 Mar 2021 04:11:54 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *env[]) {
    for (int i = 0; env[i]; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D') {
            for (int j = 4; env[i][j]; j++) {
                printf("%c", env[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
