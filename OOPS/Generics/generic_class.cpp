/*
Generics:

    - Generic programming allows to perform the same function/algorithm for
      all data types
    - Eliminates the need to create different functions for different data types
      to execute the same algorithm
    - Achieved using templates
        i) Function templates
        ii) Class templates

    Advantages:
        - Code Reusability
        - Avoid function overloading

*/


#include<iostream>
using namespace std;

//creates a template class Arithmetic
template <typename T> class Arithmetic{

    private:
        T x,y;
    
    public:
        //receives two numbers num1 and num2
        Arithmetic(T num1, T num2){ 

            x=num1;
            y=num2;
        }

        //adds x and y
        void add(){
            cout<<"The addition of "<<x<<" and "<<y<<" is "<<x+y<<endl;          
        }
};


int main(){

    Arithmetic<int> intAdd(2,3);
    Arithmetic<float> floatAdd(2.5,3.5);

    //adds the integer numbers 2 and 3
    intAdd.add();

    //adds the float numbers 2.5 and 3.5
    floatAdd.add();

    return 0;
}