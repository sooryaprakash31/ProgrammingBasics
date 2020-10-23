

class Student:

    def getData(self):
        self.__rollno = int(input("Enter Roll no "))
        self.__name = input("Enter name ")

    def displayData(self):
        print(f"Roll no: {self.__rollno} Name: {self.__name}")

s = Student() 
s.getData()
s.displayData()