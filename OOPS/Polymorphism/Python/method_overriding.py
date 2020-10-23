'''
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Method Overriding:

    - It allows to override already defined methods in base class with methods with same name in derived class.
    - The method in derived class overrides the method in base class which has the same method name.
'''

# Base class
class Vehicle:

    def use(self):
        print("Vehicles are used for transport")

    def fact(self):
        print("Vehicles need fuel to run")

# Derived class
class Car(Vehicle):
    
    # Car inherits members from Vehicle
    # use() and fact() are inherited from Vehicle

    def fact(self):
        print("Car is a type of vehicle")

# v is the object of class Vehicle
v = Vehicle()
# c is the object of class Car
c = Car()


# calling the use() using the derived class object
c.use()

# calling the fact() using the derived class object
# as there is already a method with name fact() in base class, 
# it will be overridden with the method in the derived class 

# the fact() of derived class is called
c.fact()

'''
Output:

Vehicles are used for transport
Car is a type of vehicle
'''