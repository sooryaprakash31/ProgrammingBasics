/*
Class:

    - Class is a user defined datatype which holds its own 
    members - variables and functions. 
    - The members of a class can be accessed using objects.

Object:

    - Object is an entity with some characteristics and behaviour.
    - Object is an instance of a class and used to access the members of a class.
    - Memory for a class is allocated only when the class is instantiated 
      i.e object for the class is created
*/

#include<iostream>
using namespace std;

// 'class' keyword is used while creating the class
class Person{
    
    //private members can be accessed only within the class
    private:
        string name;
        int age;

    //public members can be accessed from anywhere
    public:
        
        //constructor gets called when memory is allocated for the class
        Person(){
            cout<<"Constructor\n";
        }

        void getDetails(){
            cout<<"Enter name and age ";
            cin>>name>>age;
        }

        void printDetails(){
            cout<<"\nName: "<<name<<" Age: "<<age;
        }
        //destructor gets called when memory is destroyed for the class
        ~Person(){
            cout<<"\nDestructor";
        }
};

int main(){

    //person is the object for the class Person
    Person person;
    
    person.getDetails();
    person.printDetails();

    return 0;
}

/*

Output:
------

Constructor
Enter name and age John 30 

Name: John Age: 30
Destructor

*/