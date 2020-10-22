#include<iostream>
using namespace std;

class Complex{

    private:
        int real, imag;
    
    public:
        Complex(int r=0, int i=0){
            real = r;
            imag = i;
        }

        Complex operator+ (Complex &obj){
            
            Complex temp;
            
            temp.real = this->real + obj.real;
            temp.imag = this->imag + obj.imag;
            
            return temp;
        }

        void print(){
            cout<<"The complex number is "<<real<<"+i"<<imag;
        }

};

int main(){

    Complex c1(2,3),c2(3,4);
    
    Complex c3 = c1+c2;
    
    c3.print();

    return 0;
}