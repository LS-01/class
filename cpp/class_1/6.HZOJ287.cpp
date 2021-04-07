/*************************************************************************
	> File Name: 6.HZOJ287.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 04 Mar 2021 03:49:20 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct CMP {
    public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

template<typename T>
struct great {
    public:
    bool operator()(int a, int b) {
        return b < a;
    }
};

int main() {
    //priority_queue<int, vector<int>, CMP> q;
    priority_queue<int, vector<int>, great<int>> q;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        q.push(a);
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        sum += a + b;
        q.push(a + b);
    }
    cout << sum << endl;
    return 0;
}
