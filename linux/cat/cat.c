/*************************************************************************
	> File Name: cat.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 23 Sep 2020 10:01:33 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *in_file = fopen(argv[argc - 1], "r");
    int start = 1;
    int line = 1;
    char c = fgetc(in_file);
    char c_temp = '\0';

    int output_type = 0;
    while ((c_temp = getopt(argc, argv, "nb")) != -1) {
        switch (c_temp) {
            case 'n':
                output_type ? : (output_type = 2);
                break;
            case 'b':
                output_type = 1;
                break;
            default:
                break;
        }
    }

    while (c != EOF) {
        while (output_type && (c == '\n' || start)) {
            c_temp = c;
            c = fgetc(in_file);
            if (output_type == 1) {
                while (c == '\n') {
                    putchar(c);
                    c = fgetc(in_file);
                }
            }
            if (c == EOF) {
                printf("\n");
                break;
            }
            if (start) {
                printf("%d\t%c", line++, c_temp);
                start = 0;
            } else {
                printf("%c%d\t", c_temp, line++);
            }
        }
        (c != EOF) && putchar(c);
        c = fgetc(in_file);
    }

    fclose(in_file);
    return 0;
}
