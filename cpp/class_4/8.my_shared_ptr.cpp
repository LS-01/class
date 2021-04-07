/*************************************************************************
	> File Name: 8.my_shared_ptr.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 09 Mar 2021 03:04:32 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <map>
using namespace std;

class A {
public:
    A() { cout << "default constructor" << endl; }
    int x, y;
    ~A() { cout << "destructor" << endl; }
};

class sharedPtr {
public:
    sharedPtr();
    sharedPtr(A *);
    sharedPtr(const sharedPtr &);
    A *operator->();
    A &operator*();
    sharedPtr &operator=(const sharedPtr &);
    int use_count();
    ~sharedPtr();

private:
    void decrease_by_one();
    void increase_by_one();
    int *cnt;
    A *obj;
};

sharedPtr::sharedPtr() : obj(nullptr), cnt(nullptr) {}
sharedPtr::sharedPtr(A *obj) : obj(obj), cnt(new int(1)) {}
sharedPtr::sharedPtr(const sharedPtr &p) : obj(p.obj), cnt(p.cnt) { increase_by_one(); }
A *sharedPtr::operator->() { return obj; }
A &sharedPtr::operator*() { return *obj; }
sharedPtr &sharedPtr::operator=(const sharedPtr &p) {
    if (this->obj != p.obj) {
        decrease_by_one();
        obj = p.obj;
        cnt = p.cnt;
        increase_by_one();
    }
    return *this;
}
int sharedPtr::use_count() { return cnt ? *cnt : 0; }
void sharedPtr::decrease_by_one() {
    if (this->cnt != nullptr) {
        *(this->cnt) -= 1;
        if (*(this->cnt) == 0) {
            delete this->obj;
            delete this->cnt;
        }
    }
    return ;
}
void sharedPtr::increase_by_one() {
    if (cnt != nullptr) {
        cnt[0] += 1;
    }
    return ;
}
sharedPtr::~sharedPtr() {
    this->decrease_by_one();
    this->obj = nullptr;
    this->cnt = nullptr;
}

int main() {
    A *p1 = new A();
    p1 = nullptr;

    {
    shared_ptr<A> p2(new A());
    cout << p2.use_count() << endl;
    shared_ptr<A> p3 = p2;
    p2->x = 123; p2->y = 456;
    (*p2).x = 456;
    cout << p2.use_count() << endl;
    p2 = nullptr;//自动析构
    cout << p3.use_count() << endl;
    }
    
    {
    sharedPtr p4(new A());
    cout << p4.use_count() << endl;
    sharedPtr p5 = p4;
    p4->x = 123; p4->y = 456;
    (*p4).x = 456;
    cout << p4.use_count() << endl;
    p4 = nullptr;//自动析构
    cout << p5.use_count() << endl;
    }
    return 0;
}
