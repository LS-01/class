/*************************************************************************
	> File Name: 1.constructor.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 10:25:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public:
    Data(int x, int y) : x(x), y(y) {
        cout << "data : " << this << endl;
    }
    Data(const Data &d) {
        cout << "123 "<< &d << endl;
    }

//private:
    int x, y;
};

class A {
public:
    A() : d(3, 4), c(d){
        cout << this << " : constructor" << endl;
        cout << "c : " << &c << endl;
        cout << "d : " << &d << endl;
        cout << c.x << endl;
        cout << d.x << endl;
    }
    A(int x) : d(x, x), c(3, 4){
        cout << this << " : transform constructor" << endl;
    }
    A(const A &a) : d(a.d), c(3, 4){
        cout << this << " : copy constructor" << endl;
    }
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;
        return *this;
    }
    ~A() {
        cout << this << " : destructor" << endl;
    }
    Data c, d;
};

void add_one(int &x) {
    x += 1;
    return ;
}

int main() {
    int n = 3;
    cout << "n = " << n << endl;
    add_one(n);
    cout << "n = " << n << endl;
    A a;
    A b = a;
    A c(3);
    A d = 3;
    a = 123;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    cout << "end of main" << endl;
    return 0;
}
