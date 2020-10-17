/*
Access specifiers or Access modifiers:

    - Define the accessibility of the class members
    - There are three types of access specifiers
        i) public
       ii) private
      iii) protected
    - Default access specifier is private
        
Access modes:

    - The mode in which the child class is inherited from its parent class
    - There are three types of access modes
        i) public
       ii) private
      iii) protected


public - Access mode: 

    If the child class inherits from parent class using public mode, then
    
    | Base Class           |      Child Class         |
    | ----------------------------------------------- |
    | public members    ---|--->  public members      |
    | protected members ---|--->  protected members   |
    | private members   ---|--->  Can't be inherited  |
    

protected - Access mode: 

    If the child class inherits from parent class using protected mode, then
    
    | Base Class           |      Child Class         |
    | ----------------------------------------------- |
    | public members    ---|--->  protected members   |
    | protected members ---|--->  protected members   |
    | private members   ---|--->  Can't be inherited  |


private - Access mode:

    If the child class inhertis from parent class using private mode, then

    | Base Class           |      Child Class         |
    | ----------------------------------------------- |
    | public members    ---|--->  private members     |
    | protected members ---|--->  private members     |
    | private members   ---|--->  Can't be inherited  |

*/


#include<iostream>
using namespace std;

//Parent class
class Parent{

    public:
        int A=10;
    protected:
        int B=20;
    private:
        int C=30;

};  

//inherits using public mode
class ChildPublic : public Parent{

    /*
        A is inherited as public
        B is inherited as protected
        C can not be inherited
    */

};

//inherits using protected mode
class ChildProtected: protected Parent{

    /*
        A is inherited as protected
        B is inherited as protected
        C can not be inherited
    */

};

//inherits using private mode
class ChildPrivate: private Parent{

    /*
        A is inherited as private
        B is inherited as private
        C can not be inherited
    */

};

int main(){

    return 0;
}