/*************************************************************************
	> File Name: 7.shared_ptr.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 09 Mar 2021 03:04:32 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    A() { cout << "default constructor" << endl; }
    int x, y;
    ~A() { cout << "destructor" << endl; }
};

int main() {
    A *p1 = new A();
    p1 = nullptr;
    shared_ptr<A> p2(new A());
    cout << p2.use_count() << endl;
    shared_ptr<A> p3 = p2;
    p2->x = 123; p2->y = 456;
    (*p2).x = 456;
    cout << p2.use_count() << endl;
    p2 = nullptr;//自动析构
    cout << p3.use_count() << endl;
    return 0;
}
