/*************************************************************************
	> File Name: 4.overload.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 08 Mar 2021 03:56:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

/*
void func(int x) {
    cout << x << endl;
}
*/

int func(int x) {
    return 2 * x;
}

double func(double x) {
    return x * x;
}

int func(int x, int y) {
    return x * y;
}

/*
 * func(int)
 * func(int, double)
double func(int x, double y = 10) {
    return x * y;
}
*/

int main() {
    cout << func(2) << endl;
    cout << func(1.1) << endl;
    cout << func(2, 3) << endl;
    return 0;
}
