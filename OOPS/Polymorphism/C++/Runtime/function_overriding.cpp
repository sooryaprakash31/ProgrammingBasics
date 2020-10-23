/*

*/


#include<iostream>
using namespace std;

class Base{

    public:

        void fun1(){
            cout<<"\nBase function 1";
        }
        
        virtual void fun2(){
            cout<<"\nBase function 2";
        }

        virtual void fun3(){
            cout<<"\nBase function 3";
        }
};

class Derived:public Base{

    public:

        void fun1(){
            cout<<"\nDerived function 1";
        }

        void fun2(){
            cout<<"\nDerived function 2";
        }

        void fun3(int x){
            cout<<"\nDerived function 3";
        }
};

int main(){
    
    Base * base_ptr;
    Derived derived_ptr;

    base_ptr = &derived_ptr;

    base_ptr->fun1();

    base_ptr->fun2();

    base_ptr->fun3();


    return 0;
}