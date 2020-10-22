/*
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Compile Time Polymorphism:

    - Overloading is a compile time polymorphism where more than one method is having the same name 
      but with the different number of parameters or the type of the parameters.
    - It is acheived by function overloading and operator overloading

Operator Overloading:

    - The ability to provide the operators with a special meaning for a data type.
    - For example, the addition operator '+' can be overloaded to perform concatenation of two strings

    Syntax:
        
        return_type operator operator_symbol (argument_type reference_of_argument)

    - The following operators can not be overloaded
        i) . (dot) 
        ii) :: (scope resolution)
        iii) ?: (ternary)
        iv) sizeof (sizeof())
*/

//The following example explains the overloading of +, >> and << operators

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

        //the overloading methods for operators >> and << are declared as friend
        //so that they can access the private members of this class
        friend ostream& operator<<(ostream& out, Complex&obj);
        friend istream& operator >> (istream& in, Complex &obj);

        //prints the values of real and imag of the calling object
        void print(){
            //cout<<"The complex number is "<<real<<"+i"<<imag;
        }

};

/* 
cout and cin are objects of ostream and istream classes respectively.
To overload them <<, >> the solution is to modify the methods of ostream and istream classes 
which is not a good idea.
Alternative is to make these methods as global methods
*/

istream& operator >> (istream& in, Complex &obj){
    
    cout<<"Enter real and imaginary values ";
    
    //in is the istream object which reads values for members of obj object
    in>>obj.real>>obj.imag;

    //returns in as istream reference object
    return in;
}

ostream& operator << (ostream& out, Complex &obj){

    //out is the ostream object which prints values of members of obj object
    out<<"The Complex number is "<<obj.real<<"+i"<<obj.imag;
    
    //returns out as ostream reference object
    return out;
}

int main(){

    //objects c1 and c2 are created with values
    Complex c1,c2;
    
    //operator >> method is called by sending c1 as argument
    cin>>c1;
    
    //operator >> method is called by sending c2 as argument
    cin>>c2;

    //c1+c2 => c1.+(c2) => c1 calls the operator + function by sending c2 as argument
    //the return value from operator + function is stored in c3
    Complex c3 = c1+c2;
    
    //operator << method is called by sending c3 as argument
    cout<<c3;

    return 0;
}