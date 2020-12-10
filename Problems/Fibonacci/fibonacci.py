'''
Fibonacci number:

    - The nth number from the fibonacci sequence formed by the formula,
        Fn = Fn-1 + Fn-2 
        where F0 = 0 and F1 = 1
'''

def find_fibonacci(n):
    prev1 = 0
    prev2 = 1
    for _ in range(2,n+1):
        val = prev1 +prev2
        prev1 = prev2
        prev2 = val
    return prev2

n = int(input("Enter n "))

result = find_fibonacci(n)
print(f"The {n}th fibonacci number is {result}")