/*************************************************************************
	> File Name: 2.init.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 04 Mar 2021 09:29:48 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
    public :
    A() : x(123), y(0){}
    void say1() const {
        cout << x << endl;
        y += 1;
        cout << y << endl;
        //x = 456;
    }
    void say2() {
        x = 456;
    }
    int x;
    mutable int y;//逻辑上的const，不影响/不重要
};

int main() {
    const int x = 1;
    //x = 3;
    const A a;//核心数据没变
    a.say1();
    //a.say2();
    return 0;
}
