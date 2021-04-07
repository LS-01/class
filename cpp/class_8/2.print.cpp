/*************************************************************************
	> File Name: 2.print.cpp
	> Author: ls
	> Mail: 
	> Created Time: Wed 17 Mar 2021 02:38:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
class PRINT {
public :
    template<typename B>
    PRINT &operator()(B a) {
        cout << a << endl;
        return *this;
    }
};

int main() {
    PRINT<int> print_int;
    print_int(123);
    print_int(456);
    PRINT<string> print_string;
    print_string("hi");

    PRINT<int> print;
    print(123)("hi")(456)("ls");
    return 0;
}
