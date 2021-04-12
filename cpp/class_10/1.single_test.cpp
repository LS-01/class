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
        static bool flag = true;
        if (flag) {
            cout << "123" << endl;
            flag = false;
            single = new SingleInstance();
        }
        return single;
    }

private :
    SingleInstance() {}
    SingleInstance(const SingleInstance &) = delete;
    static SingleInstance *single;
};

SingleInstance *SingleInstance::single = SingleInstance::getInstance();

int main() {
    SingleInstance *s1 = SingleInstance::getInstance();
    SingleInstance *s2 = SingleInstance::getInstance();
    SingleInstance *s3 = SingleInstance::getInstance();
    //SingleInstance s2(*s1);
    return 0;
}
