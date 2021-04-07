/*************************************************************************
	> File Name: 6.is_prime.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 22 Mar 2021 07:20:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<int i, int n>
struct getNextI {
    static constexpr int r = (n % i ? i + 1 : 0);
};

template<int i, int n>
struct getNextN {
    static constexpr int r = (i * i <= n ? n : 0);
};

template<int i, int n>
struct __test_prime {
    static constexpr int r = __test_prime<getNextI<i, n>::r, getNextN<i, n>::r>::r;
};

template<int n>
struct __test_prime<0, n> {
    static constexpr int r = 0;
};

template<int i>
struct __test_prime<i, 0> {
    static constexpr int r = 1;
};

template<>
struct __test_prime<0, 0> {
    static constexpr int r = 1;
};

template<int n, int m1, int m2>
struct if_condition {
    static constexpr int r = (n ? m1 : m2);
};

template<int n>
struct is_prime {
    static constexpr int r = if_condition<__test_prime<2, n>::r, 1, 0>::r;
};

template<int n>
struct sum {
    static constexpr int r = n + sum<n - 1>::r;
};

template<>
struct sum<1> {
    static constexpr int r = 1;
};

template<int n>
struct getBad {
    static constexpr int r = (n <= 5);
};

template<int n>
struct getGood {
    static constexpr int r = (n > 5);
};

template<int n, int m> struct judge;

template<>
struct judge<1, 0> {
    static constexpr char *r = (char *)"bad";
};

template<>
struct judge<0, 1> {
    static constexpr char *r = (char *)"good";
};

template<int n>
struct score {
    static constexpr char *r = judge<getBad<n>::r, getGood<n>::r>::r;
};

template<int n> struct judge_even{};

template<>
struct judge_even<0> {
    static constexpr char *r = (char *)"yes";
};

template<>
struct judge_even<1> {
    static constexpr char *r = (char *)"no";
};

template<int n>
struct is_even {
    static constexpr char *r = judge_even<n % 2>::r;
};

int main() {
    cout << sum<5>::r << endl;//15
    cout << score<6>::r << endl;//good
    cout << score<4>::r << endl;//bad
    cout << is_even<3>::r << endl;//no 
    cout << is_even<4>::r << endl;//yes

    cout << is_prime<2>::r << endl;//1
    cout << is_prime<13>::r << endl;//1
    cout << is_prime<25>::r << endl;//0
    cout << is_prime<27>::r << endl;//0
    cout << is_prime<9973>::r << endl;//1
    return 0;
}
