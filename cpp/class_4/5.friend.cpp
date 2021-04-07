/*************************************************************************
	> File Name: 1.friend.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 10:25:13 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public:
    Data(int x, int y) : x(x), y(y) {
        cout << "data : " << this << endl;
    }
    friend ostream &operator<<(ostream &out, const Data &d);

private:
    int x, y;
};

ostream &operator<<(ostream &out, const Data &d) {
    out << d.x << "-" << d.y;
    return out;
}

int main() {
    Data data(10, 9);
    cout << data << endl;
    return 0;
}
