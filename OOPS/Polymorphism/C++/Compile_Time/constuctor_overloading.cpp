/*
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Compile Time Polymorphism:

    - Overloading is a compile time polymorphism where more than one method is having the same name 
      but with the different number of parameters or the type of the parameters.
    - It is acheived by function overloading and operator overloading

Constructor Overloading:
    - Like Function overloading, Constructor of a class can be overloaded
    - Multiple constructors can be created using the class name
    - The constructors are differentiated by arguments list

    Types of constructors:
        - Default constructor - receives no arguments
        - Parameterized constructor - receives arguments
        - Copy constructor - receives an object of the class as argument
*/


#include<iostream>
using namespace std;

class Constructor{

    public:

        //Default constructor
        Constructor(){
            cout<<"\nDefault constructor";
        }

        //Parameterized constructor
        Constructor(int x){
            cout<<"\nParameterized constructor";
        }

        //Copy constructor
        Constructor(Constructor & obj){
            cout<<"\nCopy constructor";
        }

};

int main(){

    //calls default constructor
    Constructor c1;
    
    //calls parameterized constructor
    Constructor c2(10);

    //calls copy constructor
    Constructor c3(c2);

    return 0;
}