/*************************************************************************
	> File Name: 1.cat.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 10 Mar 2021 10:59:01 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name = "mi") : name(name) {
        cout << "animal default constructor" << endl;
    }
    Animal(const Animal &a) : name(a.name) {
        cout << "animal copy constructor" << endl;
    }
    Animal &operator=(const Animal &a) {
        this->name = a.name;
        return *this;
    }
    void say() {
        cout << "my name is " << name << endl;
    }
    void rename(string name) {
        this->name = name;
    }
    ~Animal() {
        cout << "animal default destructor" << endl;
    }

protected:
    string name;
};

class Cat : public Animal {
public:
    Cat() : Animal("Cat mi") {
        cout << "cat default constructor" << endl;
    }
    Cat(const Cat &c) : Animal(c){
        cout << "cat copy constructor" << endl;
    }
    Cat &operator=(const Cat &c) {
        this->Animal::operator=(c);
        return *this;
    }
    void say1() {
        cout << "cat : my name is " << name << endl;
    }
    ~Cat() {
        cout << "cat default destructor" << endl;
    }
};

/*
class Tiger : public Cat {
public:
    void say2() {
        cout << "tiger : my name is " << name << endl;
    }
};
*/

class A {
public:
    A() : x(123) {}
    int x;
};

class B : virtual public A {
public:
    void setX(int x) { 
        cout << "setX &x: " << &(this->x) << endl;
        this->x = x; return ;
    }
};

class C : virtual public A {
public:
    int getX () {
        cout << "getX &x: " << &(this->x) << endl;
        return this->x;
    }
};

class D : public B, public C {};

class Father {
public:
    Father(const Father &f) = default;
};

class Son : private Father {
public:
    Son(const Son &s) : Father(s) {}
};

int main() {
    cout << sizeof(Animal) << " " << sizeof(Cat) << endl;
    Cat c;
    Cat a = c;
    //c.say();
    a.say1();
    c.say1();

    Animal *p = &c;
    p->say();

    cout << sizeof(int) << endl;
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << " " << sizeof(D) << endl;
    D d;
    cout << "d : " << &d << endl;
    cout << d.getX() << endl;
    d.setX(12345);
    cout << d.getX() << endl;
    return 0;
}
