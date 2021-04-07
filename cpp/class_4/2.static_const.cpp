/*************************************************************************
	> File Name: 2.static_const.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 08 Mar 2021 02:10:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People {
public:
    People() : say_cnt(0) {
        People::total_num += 1;
    }
    static void say_count() {
        cout << People::total_num << endl;
    }
    void say() const {
        cout << say_cnt << " hahaha, funny!" << endl;
        output();
        say_cnt += 1;
        return;
    }
    void output() {
        cout << "non-const output" << endl;
    }
    void output() const {
        cout << "const output" << endl;
    }
    ~People() {
        People::total_num -= 1;
    }
private:
    mutable int say_cnt = 0;
    static int total_num;
};

int People::total_num = 0;

int main() {
    People p1, p2;
    p1.say_count();
    p1.say();
    People::say_count();
    {
        People p3, p4;
        People::say_count();
    }
    People::say_count();
    const People p5;
    p5.say();
    return 0;
}
