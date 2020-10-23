



class Complex:
    def __init__(self, r=0,i=0):
        self.real = r
        self.imag = i

    def __str__(self):
        return f"{self.real}+i{self.imag}"

    def __add__(self,obj):
        r = self.real + obj.real
        i = self.imag + obj.imag
        return Complex(r,i)

c1 = Complex(2,3)
c2 = Complex(3,4)

c3 = c1+c2

print(c3)
