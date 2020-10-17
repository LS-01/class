/*************************************************************************
	> File Name: test.h
	> Author: ls
	> Mail: 
	> Created Time: Fri 16 Oct 2020 06:19:38 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b) \
void a##_haizei_b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_b, #a "_haizei_" #b);\
}\
void a##_haizei_b()

#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");

typedef void (*TestFunc)();
typedef struct Function {
    TestFunc func;
    const char *str;
} Function;
int RUN_ALL_TESTS();
void add_function(TestFunc, const char *);

#endif
