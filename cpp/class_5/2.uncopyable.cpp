/*************************************************************************
	> File Name: 2.uncopyable.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 10 Mar 2021 08:19:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Uncopyable {
public:
    Uncopyable() = default;
    Uncopyable(const Uncopyable &) = delete;
    Uncopyable &operator=(const Uncopyable &) = delete;
};

class A : public Uncopyable {};
class B : public Uncopyable {};
class C : public Uncopyable {};

int main() {
    A a;
    //A c = a;
    return 0;
}
