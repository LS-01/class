/*************************************************************************
	> File Name: 2.vtable.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 10 Mar 2021 11:29:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() { x = 100; y = 200;}
    virtual void say(int x) {
        cout << "this->x = " << this->x << endl;
        cout << "Class A say " << x << endl;
    }
    virtual void run() {
        cout << "Calss A run" << endl;
    }
    void reg1() { cout << "reg1 func" << endl; }
    void reg2() { cout << "reg2 func" << endl; }
    void reg3() { cout << "reg3 func" << endl; }
    void reg4() { cout << "reg4 func" << endl; }
    void reg5() { cout << "reg5 func" << endl; }
    int x, y;
};

class B : public A {
public:
    B() { x = 2000; }
    void say(int x) override {
        cout << "Class B say " << x << endl;
    }
};

class C : public A {
public:
    C() { x = 30000; }
    void run() override {
        cout << "Class C run" << endl;
    }
};

#define TEST(a) test(a, #a)
void test(A &a, string class_name) {
    cout << "Object " << class_name << endl;
    a.say(123);
    a.run();
    cout << "==========" << endl << endl;
    return ;
}

typedef void (*func)(void *, int);

int main() {
    A a;
    B b;
    C c;
    TEST(a);
    TEST(b);
    TEST(c);
    ((void **)(&b))[0] = ((void **)(&c))[0];
    TEST(b);
    ((func **)(&b))[0][0](&a, 100);

    void (A::*p[5])();
    int A::*q;
    q = &A::x;
    cout << a.*q << endl;
    q = &A::y;
    cout << a.*q << endl;

    p[0] = &A::reg1;
    p[1] = &A::reg2;
    p[2] = &A::reg3;
    p[3] = &A::reg4;
    p[4] = &A::reg5;
    for (int i = 0; i < 10; i++) {
        (a.*p[rand() % 5])();
    }
    return 0;
}
