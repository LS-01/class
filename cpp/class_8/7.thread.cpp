/*************************************************************************
	> File Name: 7.thread.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 23 Mar 2021 03:27:18 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void func(int x) {
    for (int i = 0; i < x; i++) cout << i << endl;
    return ;
}

void add_one(int &x) {
    cout << "add_one function" << endl;
    x += 1;
    return ;
}

class Task {
public :
    template<typename FUNCTION, typename ...ARGS>
    Task(FUNCTION &&f, ARGS ...args) {
        cout << "Task constructor" << endl;
        //f(args...); //右值变左值
        this->f = bind(f, forward<ARGS>(args)...);
    }
    void run() {
        f();
    }

private :
    function<void()> f;
};

int main() {
    thread t1(func, 30), t2(func, 30);
    t1.join();
    t2.join();
    
    int n = 8;
    thread t3(add_one, ref(n));
    t3.join();

    Task tk1(func, 30), tk2(func, 30);
    Task tk3(add_one, ref(n));
    tk3.run();
    tk3.run();
    tk3.run();
    cout << "hi" << endl;
    cout << n << endl;
    return 0;
}
