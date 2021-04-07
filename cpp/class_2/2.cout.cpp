/*************************************************************************
	> File Name: 2.cout.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 04:20:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#define BEGINS(x) namespace x {
#define ENDS(x) } // namespace x

BEGINS(haizei)

class ostream {
public:
    ostream &operator<<(int x);
    ostream &operator<<(const char *x);
};

ostream &ostream::operator<<(int x) {
    printf("%d", x);
    return *this;
}

ostream &ostream::operator<<(const char * x) {
    printf("%s", x);
    return *this;
}

ostream cout;

ENDS(haizei)

int main() {
    int n = 123, m = 456;
    std::cout << n << " " << m;
    std::cout << std::endl;
    haizei::cout << n << " " << m;
    std::cout << std::endl;
    return 0;
}
