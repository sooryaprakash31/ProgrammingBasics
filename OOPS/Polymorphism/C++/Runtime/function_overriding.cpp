/*
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Runtime Polymorphism:

    - Runtime polymorphism is also known as dynamic polymorphism or late binding. 
    - In runtime polymorphism, the function call is resolved at run time.
    - It is achieved by function overriding

Function Overrriding:
    
    - It enables you to provide specific implementation of the function which is already provided by its base class.
    - It is achieved by using virtual functions

Virtual Functions;

    - The idea is that virtual functions are called according to the type of the object instance pointed to or referenced, 
      not according to the type of the pointer or reference. 
    - uses 'virtual' keyword
*/

//The following example explains Function overriding using virtual functions
 
#include<iostream>
using namespace std;

class Base{

    public:

        //non-virtual function
        void fun1(){
            cout<<"\nBase function 1";
        }
        
        //virtual function
        virtual void fun2(){
            cout<<"\nBase function 2";
        }

        //virtual function
        virtual void fun3(){
            cout<<"\nBase function 3";
        }
};

class Derived:public Base{

    public:

        //derived class has definitions for already defined functions in base class
        //here fun2() and fun3() are overridden

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
    
    //creating a pointer of type Base
    Base * base_ptr;

    //creating an object for Derived
    Derived derived_ptr;

    //now base_ptr, pointer of type Base holds the address of object of derived
    base_ptr = &derived_ptr;

    //virtual functions work in a way that the compiler calls the functions
    //based on the type of object referenced (type of derived_ptr is Derived) and 
    //not based on the type of actual pointer (i.e type of base_ptr is Base)

    //fun1 is non-virtual. Hence, Base class function is called
    base_ptr->fun1();

    //fun2 is virtual. Derived class function is called
    base_ptr->fun2();

    //Eventhough fun3 is virtual, there is no exact prototype for fun3 in derived class
    //Hence, Base class function is called
    base_ptr->fun3();

    return 0;
}

/*
Output:

Base function 1
Derived function 2
Base function 3

*/