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