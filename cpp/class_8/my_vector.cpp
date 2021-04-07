/*************************************************************************
	> File Name: 3.vector.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 17 Mar 2021 02:56:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace ls {

    template<typename T>
    class vector {
    public :
        vector(int capacity = 10) : __size(0), __capacity(capacity), data(new T[__capacity]) {}
        int size() const { return __size; }
        T insert(T t, int ind) {
            if (ind > size() || ind < 0) return 0;
            expand();
            for (int i = size() - 1; i >= ind; i--) {
                data[i + 1] = data[i];
            }
            data[ind] = t;
            __size++;
            return 1;
        }
        int release(int ind) {
            if (ind >= size() || ind < 0) return 0;
            T t = data[ind];
            for (int i = ind; i < size() - 2; i++) {
                data[i] = data[i + 1];
            }
            __size--;
            //delete (T *)(&t);
            return 1;
        }
        void expand() {
            if (size() * 2 > __capacity) {
                int newcapa = __capacity * 2;
                T *newdata = new T[newcapa];
                for (int i = 0; i < size(); i++) {
                    newdata[i] = data[i];
                }
                T *old = data;
                data = newdata;
                delete[] old;
                __capacity = newcapa;
            }
            return ;
        }
        T &operator[](int ind) const {
            return data[ind];
        }


    private :
        T *data;
        int __size;
        int __capacity;
    };
}
    
template<typename T>
ostream &operator<<(ostream &out, const ls::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

int main() {
    ls::vector<int> v;
    v.insert(1, 1);
    v.insert(9, 0);
    v.insert(2, 0);
    cout << v << endl;
    v.release(1);
    cout << v << endl;
    for (int i = 0; i < 20; i++) {
        v.insert(i, i);
    }
    cout << v << endl;
    for (int i = 0; i < 5; i++) {
        v.release(i * 4);
    }
    cout << v << endl;
    return 0;
}
