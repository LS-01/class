/*************************************************************************
	> File Name: 9.sort.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 09 Mar 2021 06:30:35 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &a) {
    for (auto x : a) {
        out << x << " ";
    }
    return out;
}

bool cmp1(int a, int b) {
    return a > b;
}

class CMP {
public:
    CMP(int z = 0) : z(z) {}
    bool operator()(int a, int b) {
        //return (a < b) ^ !!(z);
        return z > 0 ? a > b : a < b;
    }
    int z;
};

namespace ls{
    void output_int_arr(int *num, int n) {
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    }

    void sort(int *arr, int l, int r, function<bool(int, int)> cmp = CMP()) {
        if (l >= r) return ;
        int x = l, y = r, z = arr[(l + r) >> 1];
        do {
            while (cmp(arr[x], z)) ++x;
            while (cmp(z, arr[y])) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        sort(arr, l, y, cmp);
        sort(arr, x, r, cmp);
        return ;
    }
};

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    //sort(arr.begin(), arr.end(), cmp1);
    sort(arr.begin(), arr.end(), CMP());//匿名对象
    cout << arr << endl;
    CMP cmp2(1);
    sort(arr.begin(), arr.end(), cmp2);
    cout << arr << endl;

    for (int i = 0; i < 3; i++) {
        cin >> n;
        int *num = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        ls::sort(num, 0, n - 1);
        ls::output_int_arr(num, n);
        ls::sort(num, 0, n - 1, CMP(1));
        ls::output_int_arr(num, n);
    }
    return 0;
}
