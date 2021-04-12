/*************************************************************************
	> File Name: 3.shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月12日 星期一 19时30分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

namespace ls {

    class shared_ptr_base_data {
    public :
        shared_ptr_base_data(void *ptr = nullptr) : cnt(new int(0)), ptr(ptr) {}
        int use_cnt() { return *cnt; }
        void *get() { return ptr; }
        virtual ~shared_ptr_base_data() {
            delete cnt;
        }

    private :
        int *cnt;
        void *ptr;
    };

    template<typename T>
    class shared_ptr_data: public shared_ptr_base_data {
    public :
        shared_ptr_data(T *ptr) : shared_ptr_base_data(ptr) {}

    private :
        static shared_ptr_base_data *data_nullptr;
    };

    shared_ptr_base_data *data_nullptr = new shared_ptr_base_data();

    template<typename T>
    class shared_ptr {
    public :
        shared_ptr(T *ptr) : data(new shared_ptr_data<T *>(ptr)) {}

    private :
        shared_ptr_base_data *data;
    };

}

class A {};

int main() {
    ls::shared_ptr<A *> p = new A();

}
