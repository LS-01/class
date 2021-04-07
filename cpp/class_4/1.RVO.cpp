/*************************************************************************
	> File Name: 1.RVO.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 08 Mar 2021 10:50:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public:
    Data() {
        cout << "Data default constructor" << endl;
    }
    Data(const Data &a) {
        cout << "Data copy constructor" << endl;
    }
};

class A {
public :
    A() {
        cout << this << " : default constructor" << endl;
    }
    A(int x) : x(x) {
        cout << this << " : transform constructor" << endl;
    }
    A(const A &a) : x(a.x + 1), d(a.d) {
        cout << this << " : copy constructor" << endl;
    }
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;;
        return *this;
    }
    int x;
    Data d;
};

A func() {
    A temp(69);
    cout << "temp : " << &temp << endl;
    return temp;
}

//g++ -fno-elide-constructors 1.RVO.cpp
int main() {
    A a = func();
    cout << "a : " << &a << endl;
    cout << a.x << endl;
    cout << "=============" << endl;
    a = func();
    return 0;
}
