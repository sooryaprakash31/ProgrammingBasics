/*
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Compile Time Polymorphism:

    - Overloading is a compile time polymorphism where more than one method is having the same name 
      but with the different number of parameters or the type of the parameters.
    - It is acheived by function overloading and operator overloading

Function Overloading:

    - Performing different operations using the same function name
    - The functions are differntiated by different arguments list. 
    - The functions must satisfy anyone or more of the following.
      i.e the functions must have different
        i) type - data type of the arguments
        ii) number - number of arguments
        iii) sequence - sequence of arguments

*/

//This example differentiates the functions by the number of arguments

#include<iostream>
using namespace std;


//number of arguments is one
float area(float side){
    cout<<"The area of the square is ";
    return side*side;
}

//number of arguments is two
float area(float length, float breadth){
    cout<<"The area of the rectangle is ";
    return length*breadth;
}

////number of arguments is three
float area(float half, float base, float height){
    cout<<"The area of the triangle is ";
    return half*base*height;
}


int main()
{
    int choice;
    float length, breadth;
    cout<<"\nArea\n1.Square\t2.Rectangle\t3.Triangle\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"\nEnter the side\n";
        cin>>length;
        //one argument
        cout<<area(length);
        break;
    case 2:
        cout<<"\nEnter length and breadth\n";
        cin>>length>>breadth;
        //two arguments
        cout<<area(length,breadth);
        break;
    case 3:
        cout<<"\nEnter the base and height\n";
        cin>>length>>breadth;
        //three arguments
        cout<<area(0.5,length,breadth);
        break;
    default:
        cout<<"\nInvalid choice";
    }
    return 0;
}