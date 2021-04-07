/*************************************************************************
	> File Name: complex.cpp
	> Author: ls
	> Mail: 
	> Created Time: Fri 05 Mar 2021 01:49:40 PM CST
 ************************************************************************/

//1.保证数据的安全性
//2.通过构造函数直接给实部和虚部赋值
//3.完成复数的加减乘除运算

#include <iostream>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class Complex {
public:
    Complex(double, double);
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;
    friend ostream &operator<<(ostream&, const Complex&);
private:
    double a;
    double b;
};

Complex::Complex(double a, double b) {
    this->a = a;
    this->b = b;
}

Complex Complex::operator+(const Complex& p) const {
    return Complex(a + p.a, b + p.b);
}

Complex Complex::operator-(const Complex& p) const {
    return Complex(a - p.a, b - p.b);
}

Complex Complex::operator*(const Complex& p) const {
    return Complex(a * p.a - b * p.b, b * p.a + a * p.b);
}

Complex Complex::operator/(const Complex& p) const {
    if (p.a == 0 && p.b == 0) {
        cout << endl << "error: division by zero" << endl;
        return Complex(0, 0);
    }
    double tmp = p.a * p.a + p.b * p.b;
    return Complex((a * p.a + b * p.b) / tmp, (b * p.a - a * p.b) / tmp);
}

ostream &operator<<(ostream &out, const Complex &p) {
    out << p.a << " + " << p.b << "i";
    return out;
}

int main() {
    double a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Complex c1(a1, b1);
    Complex c2(a2, b2);
    cout << "(" << c1 << ") + (" << c2 << ") = " << c1 + c2 << endl;
    cout << "(" << c1 << ") - (" << c2 << ") = " << c1 - c2 << endl;
    cout << "(" << c1 << ") * (" << c2 << ") = " << c1 * c2 << endl;
    cout << "(" << c1 << ") / (" << c2 << ") = " << c1 / c2 << endl;
    return 0;
}
