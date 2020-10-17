/*************************************************************************
	> File Name: main.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 14 Oct 2020 08:24:10 PM CST
 ************************************************************************/

#include <stdio.h>
//#include <gtest/gtest.h>
#include <haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(func1, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(2, 6), 8);
//    ASSERT_EQ(add(3, 3), 4);
    EXPECT_EQ(add(2, 6), 8);
}

TEST(func2, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(2, 6), 8);
//    ASSERT_EQ(add(3, 3), 4);
    EXPECT_EQ(add(2, 6), 8);
}

TEST(testfunc, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(2, 6), 8);
//    ASSERT_EQ(add(3, 3), 4);
    EXPECT_EQ(add(2, 6), 8);
}

TEST(test, funcadd) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(2, 6), 8);
//    ASSERT_EQ(add(3, 3), 4);
    EXPECT_EQ(add(2, 6), 8);
}

int main(int argc, char *argv[]) {
//    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
