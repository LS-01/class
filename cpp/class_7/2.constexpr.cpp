/*************************************************************************
	> File Name: 2.constexpr.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 15 Mar 2021 07:31:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

constexpr int func(int x) {
    return x;
}

constexpr int func1(int x) {
    if (x == 1) return 1;
    return x + func1(x - 1);
}

class A {
public : 
    constexpr A(int x) {}
};

int main() {
    const int x = 123;
    constexpr int y = 123;
    //x = 456;
    //y = 456;
    *(const_cast<int *>(&x)) = 456;
    *(const_cast<int *>(&y)) = 456;
    cout << &x << endl;
    cout << &y << endl;
    cout << const_cast<int *>(&x) << endl;
    cout << const_cast<int *>(&y) << endl;
    cout << *(&x) << endl;
    cout << *(&y) << endl;

    int n;
    cin >> n;
    const int xx = n + 123;
    constexpr int yy = 123;
    //constexpr int yy2 = n + 123;
    constexpr int yy3 = func(123);
    const A a(123);
    constexpr A b(123);

    constexpr int res = func1(50);
    cout << res << endl;
    return 0;
}
