'''
Polymorphism:

    - Polymorphism - Many forms
    - It allows an entity such as a variable, a function, or an object to have more than one form.

Compile Time Polymorphism:

    - Overloading is a compile time polymorphism where more than one method is having the same name 
      but with the different number of parameters or the type of the parameters.

    - Operator overloading is achieved using the special functions available in python.
    - Docs: https://docs.python.org/3.8/reference/datamodel.html#special-method-names
'''

#The following example explains the overloading of + and print()

class Complex:

    #initializer method
    def __init__(self, r=0,i=0):
        self.real = r
        self.imag = i

    #called when the object is used in print()
    def __str__(self):
        return f"{self.real}+i{self.imag}"

    #called when add (+) operator is used to add two objects
    def __add__(self,obj):
        r = self.real + obj.real
        i = self.imag + obj.imag
        return Complex(r,i)

#Two objects c1 and c2 are created for class Complex
c1 = Complex(2,3)
c2 = Complex(3,4)

#calls the __add__() method with c1 and sends c2 as argument.
#c1+c2 => c1.__add__(c2). The returned value is stored in c3
c3 = c1+c2

#c3 is also an object of class Complex.
#The print() statement calls the __str__()
print(c3)
