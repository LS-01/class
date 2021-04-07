/*************************************************************************
	> File Name: 1.class.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 03:36:38 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace haizei {
    class Cat {};
    class Dog {};
    class People {
    public:
        string name;
        int age;
        double height;
        double weight;

        void say(string name);
        void say1() {
            cout << "My name is " << name << endl;
        }
        void run();
    };

    void People::say(string name) {
        cout << this << endl;
        cout << "I am " << this->name << ", and " << name << endl;
    }
}

int main() {
    haizei::People ls;
    haizei::People p;
    ls.name = "ls";
    p.name = "p";

    cout << "&ls= " << &ls << endl;
    ls.say("haha");
    ls.say1();
    
    cout << "&p= " << &p << endl;
    p.say("haha");
    p.say1();
    return 0;
}
