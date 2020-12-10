#include<iostream>
using namespace std;

int find_gcd(int n1,int n2){
    if(n2==0){
        return n1;
    }
    else{
        return find_gcd(n2,n1%n2);
    }   
}

int main(){
    int n1,n2;
    cout<<"Enter two numbers\n";
    cin>>n1>>n2;
    int result = find_gcd(n1,n2);
    cout<<"\nThe Greatest Common Divisor of "<<n1<<" and "<<n2<<" is "<<result<<endl;

    return 0;
}