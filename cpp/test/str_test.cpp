/*************************************************************************
	> File Name: str_test.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 01:15:35 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello, how do you do?";
    cout << s << endl;
    
    cout << "1st: find test:(find do)" << endl;
    int do_first_place = s.find("do", 0);
    cout << do_first_place << endl;

    cout << "2nd: insert test:(insert --)" << endl;
    s.insert(7, 2, '-');
    cout << s << endl;

    cout << "3rd: substr test:(get how)" << endl;
    cout << s.substr(9, 3) << endl;

    cout << "4th: append test:(append ???)" << endl;
    s.append(3, '?');
    cout << s << endl;

    cout << "5th: compare test:(compare hello, how are you?)" << endl;
    cout << s.compare("hello, how are you?") << endl;

    cout << "6th: replace test:(replace -- to ,,)" << endl;
    s.replace(7, 2, ",,");
    cout << s << endl;
    return 0;
}
