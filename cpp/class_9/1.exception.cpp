/*************************************************************************
	> File Name: 1.exception.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 23 Mar 2021 08:58:38 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class my_exception : public exception {
public :
    my_exception() = default;
    ~my_exception() = default;
    my_exception &operator=(const my_exception &) = default;

    const char *what() { return "my_exception"; }
    string s;
};

void inner() {
    try {
        throw(my_exception());
    } catch (my_exception &e) {
        cout << e.what() << endl;
        e.s = "123";
        throw;
    } catch (exception &e) {
        cout << "e" << endl;
    }
}

void outer() {
    try {
        inner();
    } catch (my_exception &e) {
        cout << "outer exception s:" << e.s << endl;
    }
}

class Helper {
public :
    Helper() { cout << "ctor called" << endl; }
    Helper &operator=(const Helper &h) { cout << "copy called" << endl; }
    ~Helper() { cout << "dtor called" << endl; }
};

const char *foo() noexcept {
    //throw(123);
    return "123";
}

void process(int n) {
    if (n > 3) {
        throw(runtime_error("number is too big!"));
    }
}

int main() {
    try {
        foo();
    } catch (...) {
        cout << "foo" << endl;
    }

    outer();

    int age = 100;
    try {
        if (age > 90) {
            throw(age);
            cout << "not here" << endl;
        }
    } catch (int age) {
        cout << age << endl;
    }

    try {
        //Helper h = Helper();
        Helper h;
        throw("123");
    } catch (...) {
        cout << "Helper exception" << endl;
    }

    for (int i = 1; i < 6; i++) {
        try {
            process(i);
            cout << i << endl;
        } catch (runtime_error &e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
