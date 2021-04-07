/*************************************************************************
	> File Name: 3.vector.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 18 Mar 2021 01:12:08 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    friend ostream &operator<<(ostream &, const A &);

private :
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << a.x;
    return out;
}

namespace ls {

    template<typename T>
    class vector {
    public:
        vector(int n = 10);
        vector(const vector<T> &);
        vector(vector<T> &&);

        T &operator[](int);
        const T &operator[](int) const;
        int size() const;
        void push_back(const T &);
        void push_back(T &&);

        ~vector();

    private :
        int __size, __capacity;
        T *data;
    };

    template<typename T>
    vector<T>::vector(int n) : __capacity(n), __size(0), data(nullptr) {
        data = (T *)malloc(sizeof(T) * __capacity);
        return ;
    }
    
    template<typename T>
    vector<T>::vector(const vector<T> &v) : __size(v.__size), __capacity(v.__capacity) {
        data = (T *)malloc(sizeof(T) * __capacity);
        for (int i = 0; i < __size; i++) {
            new(data + i) T(v.data[i]);
        }
        return ;
    }
    
    template<typename T>
    vector<T>::vector(vector<T> &&v) : __size(v.__size), __capacity(v.__capacity), data(v.data) {
        v.data = nullptr;
        v.__size = 0;
        v.__capacity = 0;
    }
    
    template<typename T>
    T &vector<T>::operator[](int ind) {
        return data[ind];
    }
    
    template<typename T>
    const T &vector<T>::operator[](int ind) const {
        return data[ind];
    }
    
    template<typename T>
    int vector<T>::size() const {
        return __size;
    }

    template<typename T>
    void vector<T>::push_back(const T &d) {
        new(data + __size) T(d);
        __size += 1;
        return ;
    }

    template<typename T>
    void vector<T>::push_back(T &&d) {
        new (data + __size) T(move(d));
        __size += 1;
        return ;
    }

    template<typename T>
    vector<T>::~vector() {
        if (data) free(data);
        __size = 0;
        __capacity = 0;
        return ;
    }
}

ostream &operator<<(ostream &out, const vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

ostream &operator<<(ostream &out, const ls::vector<A> &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

int main() {
    vector<A> v1;
    cout << v1.size() << endl;
    v1.push_back(123);
    v1.push_back(456);
    v1.push_back(789);
    //cout << v1[0] << endl;
    ls::vector<A> v2;
    cout << v2.size() << endl;
    v2.push_back(123);
    v2.push_back(456);
    v2.push_back(789);
    cout << v2[0] << endl;

    cout << v1 << endl;
    cout << v2 << endl;
    return 0;
}
