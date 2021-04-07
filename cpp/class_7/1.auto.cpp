/*************************************************************************
	> File Name: 1.auto.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 15 Mar 2021 06:13:36 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class Base {
public:
    static int xx;
    //auto y;
private:
};

auto Base::xx = 123;
/*
void func(auto x, auto y) {

}
*/
int main() {
    //func(1, 2);
    //func(1.32, 2.9);
    //auto xx[100] = {123, 456, 678};
    int x;
    auto y = 12.3;
    if ((typeid(y).hash_code() == typeid(float).hash_code())) {
        cout << "float type" << endl;
    }
    if ((typeid(y).hash_code() == typeid(double).hash_code())) {
        cout << "double type" << endl;
    }
    Base b;
    cout << typeid(b).name() << endl;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    map<int, int> arr;
    for (int i = 0; i < 10; i++) {
        arr[rand() % 100] = rand();
    }
    //map<int, int>::iterator iter = arr.begin();
    auto iter = arr.begin();
    while (iter != arr.end()) {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
    for (auto x : arr) {//pair<int, int>
        cout << x.first << " " << x.second << endl;
    }
    cout << sizeof(x) << endl;
    cout << sizeof(y) << endl;
    return 0;
}
