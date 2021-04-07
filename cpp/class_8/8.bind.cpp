/*************************************************************************
	> File Name: 8.bind.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 23 Mar 2021 04:22:40 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

void func(int x) {
    cout << x << endl;
    return ;
}

void add(int a, int b) {
    cout << a << " + " << b << endl;
    return ;
}

void test(int &x) {
    x += 1;
    cout << "test_ref function" << endl;
    return ;
}

int main() {
    function<void()> f1 = bind(func, 123);
    f1();//func(123);

    function<void(int)> f2 = bind(add, 3, placeholders::_1);
    f2(4);

    function<void(int, int)> f3 = bind(add, placeholders::_2, placeholders::_1);
    f3(2, 4);
    auto f31 = bind(add, placeholders::_2, placeholders::_1);
    f31(1, 2, 3, 4);

    int n = 0;
    function<void()> f4 = bind(test, ref(n));
    cout << n << endl;
    f4();
    cout << n << endl;

    auto wired_func = bind(add, placeholders::_4, placeholders::_2);
    wired_func(1, 2, 3, 4);
    return 0;
}
