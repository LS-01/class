/*************************************************************************
	> File Name: 1.single.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月12日 星期一 17时13分22秒
 ************************************************************************/

#include<iostream>
#include <mutex>
using namespace std;

class SingleInstance {
public : 
    static SingleInstance *getInstance() {
        if (single == nullptr) {
            unique_lock<mutex> lock(Instance_mutex);
            if (single == nullptr) {
                single = new SingleInstance();
            }
        }
        return single;
    }

private :
    SingleInstance() {}
    SingleInstance(const SingleInstance &) = delete;
    static SingleInstance *single;
    static mutex Instance_mutex;
};

SingleInstance *SingleInstance::single = nullptr;
//SingleInstance *SingleInstance::single = SingleInstance::getInstance();
mutex SingleInstance::Instance_mutex;

int main() {
    SingleInstance *s1 = SingleInstance::getInstance();
    //SingleInstance s2(*s1);
    return 0;
}
