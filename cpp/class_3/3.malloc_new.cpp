/*************************************************************************
	> File Name: 3.malloc_new.cpp
	> Author: ls
	> Mail: 
	> Created Time: Mon 08 Mar 2021 09:56:54 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() {
        x = 0;
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
    int x;
};

class B {
public:
    B() {
        x = 1;
        //y = 2;
        cout << "B" << endl;
    }
    int x;
    //int y;
};

int main() {
    int n = 10;

    cout << "malloc int" << endl;
    int *data1 = (int *)malloc(sizeof(int) * n);
    free(data1);
    cout << "new int" << endl;
    int *data2 = new int[n];
    delete[] data2;

    cout << "malloc A" << endl;
    A *Adata1 = (A *)malloc(sizeof(A) * n);
    for (int i = 0; i < n; i++) {
        new(Adata1 + i) B();
        cout << Adata1[i].x << endl;
    }
    free(Adata1);
    cout << "new A" << endl;
    A *Adata2 = new A[n];
    delete[] Adata2;
    A *Adata3 = new A;
    delete Adata3;

    return 0;
}
