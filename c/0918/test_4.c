/*************************************************************************
	> File Name: test_4.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 18 Sep 2020 08:41:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int32_t a = 70000;

    //different value
    printf("%s\n", PRId8);
    printf("%s\n", PRId16);
    printf("%s\n", PRId32);
    printf("%s\n", PRId64);

    printf("hello" "world\n");

    printf("%" PRId32 "\n", a);

    printf("INT8_MIN = %" PRId8 "\nINT8_MAX = %" PRId8 "\n", INT8_MIN, INT8_MAX);
    printf("INT16_MIN = %" PRId16 "\nINT16_MAX = %" PRId16 "\n", INT16_MIN, INT16_MAX);
    printf("INT32_MIN = %" PRId32 "\nINT32_MAX = %" PRId32 "\n", INT32_MIN, INT32_MAX);
    printf("INT64_MIN = %" PRId64 "\nINT64_MAX = %" PRId64 "\n", INT64_MIN, INT64_MAX);
    return 0;
}
