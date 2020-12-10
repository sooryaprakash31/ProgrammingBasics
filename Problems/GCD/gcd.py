'''
Greatest Common Divisor:

    - GCD of two numbers a and b is the largest possible number that divides both the a and b

Naive approach:
    - Loop from 1 to the minimum of a and b. (GCD must be less than both a and b)
    - Checking every number if it divides both a and b
    - return the greatest value that divides both a and b

Efficient approach:
    - Euclidean Algorithm:
        - The Euclidean algorithm is based on the principle that the greatest common divisor of two numbers does not change 
          if the larger number is replaced by its difference with the smaller number. 
        - For example, 
            GCD of 252 and 105 is same as the GCD of 105 and 252-105
            i.e 21
'''


def find_gcd(n1,n2):
    if n2==0:
       return n1
    else:
        return find_gcd(n2, n1%n2) 

print("Enter two numbers")
n1,n2 = map(int, input().split())
result = find_gcd(n1,n2)

print(f"The Greatest Common Divisor of {n1} and {n2} is {result}")