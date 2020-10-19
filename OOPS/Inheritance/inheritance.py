'''
Inheritance:

    - Inheritance is a OOP concept of reusing the properties of a class
      without completely writing them again in several classes.
    - Enables Code Reusability

    Base class:

        Base class has the common members which can be reused by other classes.
    
    Child class:

        The class which inherits/uses the members from base class.

    Types:

        i) Single inheritance
        ii) Multilevel inheritance
        iii) Multiple inheritance
        iv) Hierarchical inheritance
        v) Hybrid inheritance

        Note:
            The program below follows Hierarchical inheritance
'''

#Base class
class Shape:

    def getData(self):
        self.height = int(input("Enter height "))
        self.width = int(input("Enter width "))


#Child class    
class Triangle(Shape):

    #height, width and getData() are inherited from Shape class

    def calculateArea(self):
        print("\nTrianlge")
        self.getData()
        self.area = 0.5 * self.height * self.width
        print("The area of the Triangle is ", self.area)

#Child class
class Rectangle(Shape):

    #height, width and getData() are inherited from Shape class
    
    def calculateArea(self):
        print("\nRectangle")
        self.getData()
        self.area = self.height * self.width
        print("The area of the Rectangle is ", self.area)

#t is the object of class Triangle
t = Triangle()
#r is the object of class Rectangle
r = Rectangle()

t.calculateArea()
r.calculateArea()
