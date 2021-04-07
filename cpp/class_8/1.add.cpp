/*************************************************************************
	> File Name: 1.add.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 17 Mar 2021 01:53:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    A operator+(const A &a) {
        return A(x + a.x);
    }
    friend ostream &operator<<(ostream &, const A &);

private :
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << a.x;
    return out;
}

template<typename T, typename U>
//decltype(T() + U()) add(T a, U b) {
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return *a + *b;
}

template<>
int add(int a, int b) {
    return a + 2 * b;
}

auto func(int a, int b) -> int {
    return a + b;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.3, 3.2) << endl;
    cout << add<double>(2, 3.2) << endl;
    cout << add(2, 3.2) << endl;

    decltype(1 + 2) x;
    cout << typeid(x).name() << endl;

    A a(3), b(5);
    cout << (a + b) << endl;
    cout << add(a, b) << endl;

    int n = 123, m = 456;
    int *p = &n, *q = &m;
    cout << add(p, q) << endl;
    int **pp = &p, **qq = &q;
    //cout << add(pp, qq) << endl;
    return 0;
}
