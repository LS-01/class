/*************************************************************************
	> File Name: 3.HZOJ245.cpp
	> Author: ls
	> Mail: 
	> Created Time: Thu 04 Mar 2021 02:07:08 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) cin >> a, arr.push_back(a);
    sort(arr.begin(), arr.end());
    //nth_element();
    int pos = arr[n / 2], sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += abs(arr[i] - pos);
    }
    cout << sum << endl;
    return 0;
}
