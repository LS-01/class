/*************************************************************************
	> File Name: 6.bind_order.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 17 Mar 2021 01:31:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
/*
void func1(int &x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}
*/

void func1(const int &x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}

/*
void func1(int &&x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}

void func1(const int &&x) {
    cout << __PRETTY_FUNCTION__ << " called" << endl;
    return ;
}
*/

int main() {
    int n;
    const int y = 123;
    func1(n);//func1(int &)
    func1(y);//func1(const int &)
    func1(123 + 456);//func1(int &&)
    return 0;
}
