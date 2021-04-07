/*************************************************************************
	> File Name: 5.print.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 22 Mar 2021 12:10:16 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T, typename ...ARGS>
struct N_ARGS {
    typedef T type;
    typedef N_ARGS<ARGS...> rest;
};

template<typename T>
struct N_ARGS<T> {
    typedef T type;
    typedef T last;
};


template<int N, typename T, typename ...ARGS>
struct NEW_N_ARGS {
    typedef typename NEW_N_ARGS<N - 1, ARGS...>::type type;
    static int last() {
        return NEW_N_ARGS<N - 1, ARGS...>::last();
    }
};

template<typename T, typename ...ARGS>
struct NEW_N_ARGS<1, T, ARGS...> {
    typedef T type;
    static int last() {
        return 0;
    }
};

template<typename T>
struct NEW_N_ARGS<1, T> {
    typedef T type;
    static int last() {
        return 1;
    }
};

template<typename T>
void print(T a) {
    cout << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(T a, ARGS ...args) {
    cout << a << " next type : " << typeid(typename N_ARGS<ARGS...>::type).name() << endl;
    print(args...);
    return ;
}

#define Test(func...) cout << #func << " = " << func << endl

int main() {
    print(123, 45.6);
    print(123, "hi", 46.9);
    N_ARGS<int, int, double, double>::type x;
    N_ARGS<int, int, double, double>::rest::type y;
    N_ARGS<int, int, double, double>::rest::rest::type z;
    N_ARGS<int, int, double, double>::rest::rest::rest::last w;
    //N_ARGS<int, int, int, double, double>::rest::rest::rest::last w;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    cout << typeid(w).name() << endl;

    NEW_N_ARGS<1, int, int, double, double>::type xx;
    NEW_N_ARGS<2, int, int, double, double>::type yy;
    NEW_N_ARGS<3, int, int, double, double>::type zz;
    NEW_N_ARGS<4, int, int, double, double>::type ww;
    cout << typeid(xx).name() << endl;
    cout << typeid(yy).name() << endl;
    cout << typeid(zz).name() << endl;
    cout << typeid(ww).name() << endl;
    Test(NEW_N_ARGS<1, int, int, double, double>::last());
    Test(NEW_N_ARGS<2, int, int, double, double>::last());
    Test(NEW_N_ARGS<3, int, int, double, double>::last());
    Test(NEW_N_ARGS<4, int, int, double, double>::last());
    return 0;
}
