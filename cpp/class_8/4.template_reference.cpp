/*************************************************************************
	> File Name: 4.template_reference.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 18 Mar 2021 02:39:09 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace ls {

template<typename T>
void swap(T &&a, T &&b) {
    typename remove_reference<T>::type c;
    c = a; a = b; b = c;
    return ;
}

}

int main() {
    int n = 123, m = 456;
    ls::swap(n, m);
    cout << n << " " << m << endl;
    //ls::swap(789, n);
    return 0;
}
