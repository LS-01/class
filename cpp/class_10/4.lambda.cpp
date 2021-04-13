/*************************************************************************
	> File Name: 4.lambda.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 13 Apr 2021 10:16:11 AM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

function<int(int)> func(int x) {
    int n = 123;
    //return [&](int k) -> int { return k * n + x; };
    return [=](int k) -> int { return k * n + x; };
}

int main() {
    auto test = func(3);
    cout << test(3) << endl;

    auto add = [](int a, int b) -> int { return a + b; };
    auto add3 = [](int a, int b) -> int { return a + b; };
    function<int(int, int)> add2 = add;
    cout << add(1, 3) << endl;
    cout << typeid(add).name() << endl;
    cout << typeid(add2).name() << endl;
    cout << typeid(add3).name() << endl;
    
    int n = 12;
    auto times = [&n, add](int k) {
        cout << add(4, 5) << endl;
        return n * k;
    };
    cout << times(3) << endl;
    n = 15;
    cout << times(3) << endl;

    cout << test(3) << endl;
    return 0;
}
