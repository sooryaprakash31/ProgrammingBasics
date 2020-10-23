'''
Encapsulation:

    - The concept of restricting access to the sensitive properties of a class.
    - Encapsulation can be achieved by making the properties which we want to restrict access as private members.

    The access to the members of a class can be restricted by making them private members 
    i.e using __ (double underscore) infront of them while naming them.

'''

class Student:

    def getData(self):
        self.__rollno = int(input("Enter Roll no "))
        self.__name = input("Enter name ")

    def displayData(self):
        print(f"Roll no: {self.__rollno} Name: {self.__name}")

s = Student() 
s.getData()
s.displayData()