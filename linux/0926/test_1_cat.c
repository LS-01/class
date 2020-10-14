/*************************************************************************
	> File Name: test_1_cat.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 26 Sep 2020 02:08:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void cat_file(const char*);

int num = 0, b_flag = 0, n_flag = 0;

// ./a.out -b -n file
int main(int argc, char *argv[]) {
    char ch;
    while ((ch = getopt(argc, argv, "nb")) != -1) {
        switch (ch) {
            case 'b' :
                b_flag = 1;
                break;
            case 'n' : 
                n_flag = 1;
                break;
            default :
                fprintf(stderr, "Usage : %s [-b|-n] file\n", argv[0]);
                exit(1);//return 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%s ", argv[i]);
    }
    printf("\noptind = %d\n", optind);
    for (int i = optind; i < argc; i++) {
        cat_file(argv[i]);
    }
    return 0;
}

void cat_file(const char *file) {
    FILE *fp;
    if ((fp = fopen(file, "r")) == NULL) {
        perror(file);
        exit(1);
    }
    char buff[1024] = {0};
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        if (b_flag == 0 && n_flag == 0) {
            printf("%s", buff);
            continue;
        }
        if (buff[0] != '\n') {
            num++;
            printf("%d\t%s", num, buff);
        } else {
            if (n_flag == 1 && b_flag == 0) {
                num++;
                printf("%d\t\n", num);
            } else {
                printf("\n");
            }
        }
    }
    fclose(fp);
    return;
}
