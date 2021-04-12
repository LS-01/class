/*************************************************************************
	> File Name: 2.visitor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月12日 星期一 17时59分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A;
class B;
class C;
class D;
class E;

class Base {
public :
    class IVisitor {
    public :
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void say() = 0;
    virtual void accept(IVisitor *) = 0;
    virtual ~Base() {}
};

class A : public Base{
public :
    void say() override {
        cout << "Class A" << endl;
    }
    void accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    } 
};

class B : public Base{
public :
    void say() override {
        cout << "Class B" << endl;
    }
    void accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    } 
};

class C : public Base{
public :
    void say() override {
        cout << "Class C" << endl;
    }
    void accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    } 
};

class D : public Base{
public :
    void say() override {
        cout << "Class D" << endl;
    }
    void accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    } 
};

class E : public Base{
public :
    void say() override {
        cout << "Class E" << endl;
    }
    void accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    } 
};

class OutputVisitor : public Base::IVisitor {
public :
    void visit(A *obj) {
        cout << "func A" << endl;
    }
    void visit(B *obj) {
        cout << "func B" << endl;
    }
    void visit(C *obj) {
        cout << "func C" << endl;
    }
    void visit(D *obj) {
        cout << "func D" << endl;
    }
    void visit(E *obj) {
        cout << "func E" << endl;
    }
};

class CalcVisitor : public Base::IVisitor {
public :
    CalcVisitor(int &x) : x(x) {}
    void visit(A *obj) {
        x *= 2;
    }
    void visit(B *obj) {
        x -= 3;
    }
    void visit(C *obj) {
        x += 6;
    }
    void visit(D *obj) {
        x /= 3;
    }
    void visit(E *obj) {
        x -= 2;
    }

private :
    int &x;
};

void func_A() {
    cout << "func A" << endl;
}
void func_B() {
    cout << "func B" << endl;
}
void func_C() {
    cout << "func C" << endl;
}
void func_D() {
    cout << "func D" << endl;
}
void func_E() {
    cout << "func E" << endl;
}

int main() {
    srand(time(0));
    Base *p[5] = {nullptr};
    for (int i = 0; i < 5; i++) {
        switch (rand() % 5) {
            case 0: p[i] = new A(); break;
            case 1: p[i] = new B(); break;
            case 2: p[i] = new C(); break;
            case 3: p[i] = new D(); break;
            case 4: p[i] = new E(); break;
        }
        p[i]->say();
    
        //中大型项目中，容易出现潜在bug（新加子类可能忘记修改关键代码）
        //效率问题
        /*
        if (dynamic_cast<A *>(p)) {
            func_A();
        } else if (dynamic_cast<B *>(p)) {
            func_B();
        } else if (dynamic_cast<C *>(p)) {
            func_C();
        } else if (dynamic_cast<D *>(p)) {
            func_D();
        } else if (dynamic_cast<E *>(p)) {
            func_E();
        }*/
        OutputVisitor vis;
        p[i]->accept(&vis);
    }
    int x = 1;
    CalcVisitor vis(x);
    for (int i = 0, pre = x; i < 5; i++) {
        p[i]->accept(&vis);
        cout << pre << " -> " << x << endl;
    }
    cout << x << endl;

    return 0;
}
