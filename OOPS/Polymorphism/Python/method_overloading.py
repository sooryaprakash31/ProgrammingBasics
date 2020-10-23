'''
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Method Overloading:

    - Performing different operations using the same method name.
    - Python does not support method overloading as it does not uses arguments as the method signature
      If there are multiple methods with the same name, it will throw an error

'''

# Method overloading in python can be achieved by the following method. 
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


'''
Output:

Sum of 1 and 2 is 3
Sum of 1,2 and 3 is 6
'''
