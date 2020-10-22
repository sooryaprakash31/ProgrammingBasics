#include<iostream>
using namespace std;


float area(float length, float breadth){
    cout<<"The area of the rectangle is ";
    return length*breadth;
}
float area(float side){
    cout<<"The area of the square is ";
    return side*side;
}
float area(float half, float base, float height){
    cout<<"The area of the triangle is ";
    return half*base*height;
}


int main()
{
    int choice;
    float length, breadth;
    cout<<"Area\n1.Rectangle\t2.Square\t3.Triangle\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"\nEnter length and breadth\n";
        cin>>length>>breadth;
        cout<<area(length,breadth);
        break;
    case 2:
        cout<<"\nEnter the side\n";
        cin>>length;
        cout<<area(length);
        break;
    case 3:
        cout<<"\nEnter the base and height\n";
        cin>>length>>breadth;
        cout<<area(0.5,length,breadth);
        break;
    default:
        cout<<"\nInvalid choice";
    }
    return 0;
}