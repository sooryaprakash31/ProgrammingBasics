'''
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Compile Time Polymorphism:

    - Overloading is a compile time polymorphism where more than one method is having the same name 
      but with the different number of parameters or the type of the parameters.

    - Python does not support compile time polymorphism or method overloading.
      If there are multiple methods with the same name, it will throw an error

'''

# Method overloading can be achieved by the following method

def sum(a=None,b=None,c=None):
    s = 0
    if c==None:
        s=a+b
    else:
        s=a+b+c
    return s

print("Sum of 1 and 2 is",sum(1,2))

print("Sum of 1,2 and 3 is",sum(1,2,3))