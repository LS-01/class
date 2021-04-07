/*************************************************************************
	> File Name: 3.default_delete.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 08 Mar 2021 02:51:57 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() = default;
    A &operator=(int x) {
        this->x = x;
        return *this;
    }
    int x;

private:
    A(const A &) = delete;
    A &operator=(A &a);
    const A &operator=(const A &a) const;
};

int main() {
    A a;
    A b;
    (a = 123) = 456;
    cout << a.x << endl;
    //A c = b;
    //a = b;
    return 0;
}
