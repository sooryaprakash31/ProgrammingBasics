/*
Inheritance:

    - Inheritance is a OOP concept of reusing the properties of a class
      without completely writing them again in other classes.
    - Enables Code Reusability

    Base class:

        Base class has the common members which can be reused by other classes.
    
    Child class:

        The class which inherits/uses the members from base class.

    Types:

        i) Single inheritance
        ii) Multilevel inheritance
        iii) Multiple inheritance
        iv) Hierarchical inheritance
        v) Hybrid inheritance

        Note:
            The program below follows Hierarchical inheritance
*/

#include<iostream>
using namespace std;

class Shape{
    //Base class

    protected:
        int height;
        int width;
        float area;

        void getData(){
            cout<<"\nEnter height and width ";
            cin>>height>>width;
        }

};

class Triangle: public Shape{
    
    //Child class

    //height, width, area and getData() are inherited from the Shape class
    //the inherited members are available as protected members

    public:
        void calculateArea(){
            cout<<"\nTriangle";
            getData();
            area = 0.5 * width * height;
            cout<<"\nThe area of the Triangle is "<<area;
        }
};

class Rectangle: public Shape{
    
    //Child class

    //height, width, area and getData() are inherited from the Shape class
    //the inherited members are available as protected members

    public:
        void calculateArea(){
            cout<<"\nRectangle";
            getData();
            area = height * width;
            cout<<"\nThe perimeter of the rectangle is "<<area;
            
        }
};

int main(){

    //t is the object of class Triangle
    Triangle t;
    //r is the object of class Rectangle
    Rectangle r;

    t.calculateArea();
    r.calculateArea();    

    return 0;
}