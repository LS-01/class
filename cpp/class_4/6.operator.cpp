/*************************************************************************
	> File Name: 6.operator.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 08 Mar 2021 04:17:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public:
    Point();
    Point(int, int);
    Point operator+(const Point &);
    Point &operator+=(int);
    int operator[](string);
    int getX() {return x;}
    int getY() {return y;}

private:
    friend Point operator+(const Point &, const Point &);
    friend ostream &operator<<(ostream &, const Point &);
    int x, y;
};

class PPoint {
public:
    PPoint(Point *p) : p(p) {}
    Point *operator->() {
        return p;
    }

private:
    Point *p;
};

class ADD {
public:
    ADD(int c) : c(c) {}
    int operator()(int a, int b) {
        return a + b + c;
    }

private:
    int c;
};

//Point::Point() : x(0), y(0) {}
Point::Point() : Point(0, 0) {}
Point::Point(int x, int y) : x(x), y(y) {}

Point Point::operator+(const Point &p) {
    cout << "inner +" << endl;
    Point c(x + p.x, y + p.y);
    return c;
}

Point &Point::operator+=(int x) {
    this->x += x;
    this->y += x;
    return *this;
}

int Point::operator[](string s) {
    if (s == "x") return x;
    if (s == "y") return y;
    return 0;
}

Point operator+(const Point &a, const Point &b) {
    cout << "outer +" << endl;
    Point c(a.x + b.x, a.y + b.y);
    return c;
}

ostream &operator<<(ostream &out, const Point &p) {
    cout << p.x << ", " << p.y;
    return out;
}

int main() {
    ADD add(5);
    cout << add(6, 7) << endl;
    Point a(3, 4);
    Point b(7, 9);
    cout << a["x"] << endl;
    cout << a["y"] << endl;
    Point c = a + b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    a += 2;
    cout << a << endl;

    PPoint p = &a;
    cout << p->getX() << " " << p->getY() << endl;
    return 0;
}
