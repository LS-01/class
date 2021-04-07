/*************************************************************************
	> File Name: test.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 09:38:22 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
struct comp {
    public:
    bool operator()(T a, T b) {
        return b < a;
    }
};

void print_arr(vector<int> *arr) {
    for (int n : *arr) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a{1, 9, 2, 8, 3, 7, 4, 6, 5};
    nth_element(a.begin(), a.begin() + 2, a.end());
    print_arr(&a);
    nth_element(a.begin(), a.begin() + 2, a.end(), comp<int>());
    print_arr(&a);
    return 0;
}
