/*************************************************************************
	> File Name: rand_huff.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 05 Jan 2021 09:03:15 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int arr[26], sum = 0;
    for (int i = 0; i < 26; i++) {
        arr[i] = rand() % 1000;
        sum += arr[i];
    }
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %lf\n", i + 'A', (double)1.0 * arr[i] / sum);
    }

    return 0;
}
