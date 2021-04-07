/*************************************************************************
	> File Name: 1.animal.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 10 Mar 2021 10:46:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name) : name(name) {}
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
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

int main() {
    Cat a("Tom");
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    cout << "=============" << endl;

    #define MAX_N 10
    srand(time(0));
    Animal **zoo = new Animal*[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        switch (rand() % 3) {
            case 0: zoo[i] = new Cat("Cat"); break;
            case 1: zoo[i] = new People("People"); break;
            case 2: zoo[i] = new Bat("Bat"); break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        zoo[i]->run();
    }
    #undef MAX_N
    return 0;
}
