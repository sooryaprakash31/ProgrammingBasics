'''
Class:

    - Class is a user defined datatype which holds its own 
    members - variables and functions. 
    - The members of a class can be accessed using objects.

Object:

    - Object is an entity with some characteristics and behaviour.
    - Object is an instance of a class and used to access the members of a class.

'self' keyword:

    - Reference to the current instance of the class
    - Can be user-defined
    - Must be the first argument in the methods
'''

#'class' keyword is used for creating a class
class Person:

    #class attribute
    Temp = ""

    #Initializer is called when a class is instantiated
    def __init__(self):
        print("Initializer")
        
        #instance attributes
        self.name = ""
        self.age = 0

    def getDetails(self):
        self.name = input("Enter name ")
        self.age = int(input("Enter age "))
        
        #accessing class attribute with class name
        Person.Temp = "Hello World"

    def printDetails(self):
        print("Name:",self.name, " Age:",self.age)
        print(Person.Temp)

    #Destructor is called when all the references to the object have been deleted
    def __del__(self):
        print("Destructor")

#person is the object of class Person
person = Person()

person.getDetails()
person.printDetails()


'''
Output:
------

Initializer
Enter name John
Enter age 30
Name: John  Age: 30
Hello World
Destructor

'''