/*
Exception Handling:

    - This helps to avoid the program crash due to a segment of code in the program
    - Exception handling allows to manage the segments of program which may lead to errors in runtime
    and avoiding the program crash by handling the errors in runtime.

    try: represents a block of code that can throw an exception.

    catch: represents a block of code that is executed when a particular exception is thrown.
    
    throw: Used to throw an exception. Also used to list the exceptions that a function throws, but doesn’t handle itself.
*/


#include<iostream>
#include<iomanip>
using namespace std;

//function to perform division
float divide(float dividend, float divisor){

    float result = dividend/divisor;
    return result;
}

int main(){

    float dividend,divisor;
    cout<<"Enter dividend and divisor\n";
    cin>>dividend>>divisor;
    
    //the divisor must be non-zero for the division to work
    //the value of divisor is only known in the runtime, 
    //hence enclosing the segment in try{} will help us to manage if any exception occurs
    try{
        
        //if the divisor is zero, then throw an error message using 'throw'
        if(divisor==0){
            throw "Divisor is zero!";
        }

        //else executes the divide()
        else{
            cout<<setprecision(3)<<divide(dividend,divisor);
        }
    }

    //catches the error thrown by throw statement
    catch(const char * error){

        //printing the error message
        cout<<error;
    }

    //catch(...) will catch the error thrown by throw 
    //if all of the previous catch blocks mismatches with the error thrown 
    
    //works as a default catch block 
    catch(...){
        cout<<"Error occured!";
    }
    return 0;
}