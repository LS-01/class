/*************************************************************************
	> File Name: 4.HZOJ166.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 04 Mar 2021 02:15:14 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> n >> s2;
    cout << s1.size() << endl;
    s1.insert(n - 1, s2);
    cout << s1 << endl;
    cout << s1.size() - s1.rfind("x") << endl;
    return 0;
}
