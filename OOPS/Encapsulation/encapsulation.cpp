/*
Encapsulation:

    - The concept of restricting access to the sensitive properties of a class.
    - Encapsulation can be achieved by making the properties which we want to restrict access as private members.


    The access to members of a class can be restricted by declaring them under private access specifier
*/


#include<iostream>
using namespace std;

class Student{

    private:
        int rollno;
        string name;
    
    public:
        void getData(){
            cout<<"Enter rollno and name \n";
            cin>>this->rollno>>this->name;
        }

        void displayData(){
            cout<<"Roll no: "<<this->rollno<<" Name: "<<this->name;
        }
};

int main(){

    Student s1;

    s1.getData();

    s1.displayData();

    return 0;
}