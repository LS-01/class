/*************************************************************************
	> File Name: 5.HZOJ216.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 04 Mar 2021 03:39:20 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    map<string, int> h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        h[s.substr(3, s.size())] += 1;
    }
    for (auto iter = h.begin(); iter != h.end(); iter++) {
        for (int i = 0; i < iter->second; i++) cout << iter->first << endl;
    }
    return 0;
}
