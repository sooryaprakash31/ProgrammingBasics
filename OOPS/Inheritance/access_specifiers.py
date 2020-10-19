'''
Python allows the accessibility of all members from anywhere publicly.
There is no private or protected access specifier.

But, 

i) _ (single underscore) is used to denote the private members. It does not affect the accessibility. 
    [A convention that the members should not be used from outside the class]

ii) __ (double underscore) restricts direct access to the member from the instance.
    But the member can be accessed using the class name.

'''

#Base class
class Parent:

    def _printName(self):
        print("Single Underscore method")

    def __printName(self):
        print("Double Underscore method")

#Parent class
class Child(Parent):

    #inherits all members from Parent
    pass


c = Child()
c._printName()
c._Parent__printName()


'''
Output:

Single Underscore method
Double Underscore method
'''