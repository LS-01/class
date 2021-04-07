/*************************************************************************
	> File Name: 10.random.cpp
	> Author: ls
	> Mail: 
	> Created Time: Tue 23 Mar 2021 06:55:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace ls {

    static int __seed = 3;
    void srand(int seed) {
        __seed = seed;
        return ;
    }
    int rand() {
        return __seed = __seed * 3 % 101;
    }

}

int main() {
    ls::srand(time(0));
    for (int i = 0; i < 10; i++) {
        cout << ls::rand() << endl;
    }
    srand(time(0));
    rand();
    return 0;
}
