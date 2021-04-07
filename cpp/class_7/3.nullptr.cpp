/*************************************************************************
	> File Name: 3.nullptr.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 16 Mar 2021 02:16:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void func(int x) {
    cout << x << endl;
    return ;
}

void func(int *x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}

int main() {
    //cout << NULL << endl;
    //cout << nullptr << endl;
    if (NULL) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    if (nullptr) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    func(nullptr);
    //func(NULL);

    cout << typeid(NULL).name() << endl;
    cout << typeid(nullptr).name() << endl;
    return 0;
}
