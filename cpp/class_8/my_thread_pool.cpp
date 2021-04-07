/*************************************************************************
	> File Name: my_thread_pool.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 24 Mar 2021 08:52:48 AM CST
 ************************************************************************/

#include <iostream>
#include <functional>
#include <thread>
#include <queue>
using namespace std;

template<typename FUNCTION>
class my_thread_pool {
public :
    my_thread_pool(int size = 4) : size(size) {
        t = (thread *)malloc(sizeof(thread) * size);
    }
    int add_task(FUNCTION &&func) {
        tasks.push(func);
        run_task();
    }
    void run_task() {
        if (!tasks.empty()) {
            for (int i = 0; i < size; i++) {
                if (t[i].joinable()) {
                    new (t[i])thread(ref(tasks.front()));
                    t[i].join();
                    tasks.pop();
                }
            }
        }
    }

private :
    int size;
    thread *t;
    queue<FUNCTION> tasks;
};

void test() {
    cout << "test" << endl;
}

int main() {
    my_thread_pool<function<void()>> mtp;
    mtp.add_task(test);
    return 0;
}
