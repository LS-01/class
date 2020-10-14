#include <stdio.h>
#include <stdlib.h>
#include "roman.h"

int main(int argc, char *argv[]) {
    int line_nt_d = 1;
    char *line_nt_r_p = (char *)malloc(sizeof(char));
    int is_d = (argv[1][1] == 'd' ? 1 : 0);

    FILE *in_file = fopen(argv[2], "r");
    if (argc < 3) {
        in_file = stdin;
    } else {
        in_file = fopen(argv[2], "r");
    }
    
    FILE *out_file = NULL;
    if (argc > 3) {
        out_file = fopen(argv[3], "w");
    } else {
        out_file = stdout;
    }

    char ch = '\0';
    char ch_first = '\0';
    int start = 1;
    while (ch != EOF) {
        ch = fgetc(in_file);
        while (ch == '\n' || start) {
            start || fputc('\n', out_file);
            start && (ch_first = ch);
            ch = fgetc(in_file);
            ch != EOF && (is_d ? fprintf(out_file, "%d\t", line_nt_d) : fprintf(out_file, "%s\t", to_roman_numeral(line_nt_r_p, line_nt_d)));
            line_nt_d++;
            start && fputc(ch_first, out_file);
            start && (start = 0);
            if (ch == EOF) {
                break;
            }
        }
        ch == '\n' || ch == EOF || fputc(ch, out_file);
    }
    fclose(out_file);
    fclose(in_file);
    return 0;
}
