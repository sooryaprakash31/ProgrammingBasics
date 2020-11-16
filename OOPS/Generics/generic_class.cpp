#include<iostream>
using namespace std;

template <typename T> class Arithmetic{

    private:
        T x,y;
    
    public:
        Arithmetic(T num1, T num2){
            x=num1;
            y=num2;
        }

        void add(){
            cout<<"The addition of "<<x<<" and "<<y<<" is "<<x+y<<endl;          
        }
};


int main(){

    Arithmetic<int> intAdd(2,3);
    Arithmetic<float> floatAdd(2.5,3.5);

    intAdd.add();

    floatAdd.add();


    return 0;
}