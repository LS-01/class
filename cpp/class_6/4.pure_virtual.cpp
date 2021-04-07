/*************************************************************************
	> File Name: 4.pure_virtual.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 10 Mar 2021 10:46:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name) : name(name) {}
    virtual void run() = 0;
    virtual void getName() final {}
    virtual void fl1() {}

private:
    string name;
};

class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}
    void run() override final {
        cout << "I can run with four legs" << endl;
    }
    //void getName() {}
    //void fll() override {}
};

class Tiger : public Cat {
public:
    Tiger(string name) : Cat(name) {}
    //void run() {}
};

class People : public Animal {
public:
    People(string name) : Animal(name) {}
    void run() {
        cout << "I can run with two legs" << endl;
    }
};

class Bat : public Animal {
public:
    Bat(string name) : Animal(name) {}
    void run() {
        cout << "I can fly" << endl;
    }
};

class House : public Animal {
public:
    House() : Animal("House") {}
    void run() override {
        cout << "House, I can run with four legs" << endl;
    }
};

int main() {
    House h;
    h.run();
    return 0;
}
