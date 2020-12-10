/*
Fibonacci number:

    - The nth number from the fibonacci sequence formed by the formula,
        Fn = Fn-1 + Fn-2 
        where F0 = 0 and F1 = 1

*/

#include<iostream>
using namespace std;

long long find_fibonacci(long long n){
    
    long long prev1=0;
    long long prev2=1;

    for(long long int i=2;i<=n;i++){
        long long value = prev1+prev2;
        prev1 = prev2;
        prev2 = value;
    }  
    return prev2;
}


int main(){
    
    long long n;
    cout<<"Enter n\n";
    cin>>n;
    long long result = find_fibonacci(n);
    cout<<"The "<<n<<"th fibonacci number is "<<result<<endl;

    return 0;
}