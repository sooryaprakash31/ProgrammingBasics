#include<iostream>
using namespace std;

class Complex{

    private:
        int real, imag;
    
    public:

        //constructor for Complex class
        //if arguments are not passed, initializes with the default values
        Complex(int r=0, int i=0){
            real = r;
            imag = i;
        }

        //overloading + operator
        /*
        Syntax:
        return_type operator operator_symbol (argument_type reference_of_argument)
        */
        //receives object obj as reference of type Complex
        Complex operator + (Complex &obj){
            
            Complex temp;
            
            //the values of real of obj and real of the calling object 
            //will be added and stored in real of temp
            temp.real = this->real + obj.real;
            
            //the values of imag of obj and imag of the calling object 
            //will be added and stored in imag of temp
            temp.imag = this->imag + obj.imag;

            //returning object temp which is of type Complex            
            return temp;
        }

        //prints the values of real and imag of the calling object
        void print(){
            cout<<"The complex number is "<<real<<"+i"<<imag;
        }

};

int main(){

    //objects c1 and c2 are created with values
    Complex c1(2,3),c2(3,4);

    //c1+c2 => c1.+(c2) => c1 calls the operator + function by sending c2 as argument
    //the return value from operator + function is stored in c3
    Complex c3 = c1+c2;
    
    //the stored value is printed by calling print() with c3
    c3.print();

    return 0;
}