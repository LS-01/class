/*************************************************************************
	> File Name: 4.right_value.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 16 Mar 2021 02:35:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define func(x) __func(x, "func("#x")")
#define func2(x) __func2(x, "func2("#x")")

void __func2(int &x, const char *str) {
    cout << str << " is left value" << endl;
}

void __func2(int &&x, const char *str) {
    cout << str << " is right value" << endl;
}

void __func2(double &&x, const char *str) {
    cout << str << "is double value" << endl;
}

void __func(int &x, const char *str) {
    cout << str << " is left value" << endl;
    func2(x);
}

void __func(int &&x, const char *str) {
    cout << str << " is right value" << endl;
    func2(x);
    func2(move(x));
    func2(forward<int &&>(x));
    func2(forward<double &&>(x));
}

namespace ls {
    class vector {
    public :
        vector(int n = 10) : __size(n), data(new int[n]) { 
            cout << "default constructor" << endl; 
        }
        vector(const vector &v) : __size(v.size()), data(new int[__size]) {
            cout << "deep copy costructor" << endl;
            for (int i = 0; i < size(); i++) data[i] = v[i];
            return ;
        }
        vector(vector &&v) : __size(v.size()), data(v.data) {
            cout << "move constructor" << endl;
            v.data = nullptr;
            v.__size = 0;
            return ;
        }
        vector operator+(const vector &v) {
            vector ret(v.size() + this->size());
            vector &now = *this;
            for (int i = 0; i < size(); i++) {
                ret[i] = now[i];
            }
            for (int i = size(); i < ret.size(); i++) {
                ret[i] = v[i - size()];
            }
            return ret;
        }
        int &operator[](int ind) const {
            return this->data[ind];
        }
        int size() const { return __size; }
        ~vector() {
            if (data) delete[] data;
            data = nullptr;
            __size = 0;
        }

    private :
        int __size;
        int *data;
    };
}

ostream &operator<<(ostream &out, const ls::vector &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

class A {
public :
    A operator+(int x){}
    A &operator+=(int x){}
};

int main() {
    ls::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    ls::vector v3(v1 + v2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    ls::vector v4(move(v1));
    cout << v1 << endl;
    cout << v4 << endl;
    int x = 1234, y = 5678;
    func(1234);
    func(x);
    func(x + y);
    func(x++);
    func(++x);
    func(x + 123);
    func(x *= 2);
    func(y += 3);
    func(y * 3);
    return 0;
}
