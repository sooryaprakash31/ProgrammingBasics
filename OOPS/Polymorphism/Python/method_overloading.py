'''
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Compile Time Polymorphism:

    - Overloading is a compile time polymorphism where more than one method is having the same name 
      but with the different number of parameters or the type of the parameters.

    - Python does not support method overloading.
      If there are multiple methods with the same name, it will throw an error

'''

# Method overloading can be achieved by the following method. 
# But this is not a good approach.

def sum(a=None,b=None,c=None):
    s = 0
    #if c is None, then only a and b are passed
    if c==None:
        s=a+b
    #if c is not None, then a,b and c are passed
    else:
        s=a+b+c
    return s


#executes sum() for two arguments
print("Sum of 1 and 2 is",sum(1,2))

#executes sum() for three arguments
print("Sum of 1,2 and 3 is",sum(1,2,3))

