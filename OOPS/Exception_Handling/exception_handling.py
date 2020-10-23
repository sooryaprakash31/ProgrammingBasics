'''
Exception Handling:

    - This helps to avoid the program crash due to a segment of code in the program
    - Exception handling allows to manage the segments of program which may lead to errors in runtime
    and avoiding the program crash by handling the errors in runtime.

    try - represents a block of code that can throw an exception.

    except - represents a block of code that is executed when a particular exception is thrown.

    else - represents a block of code that is executed when there is no exception

    finally - represents a block of code that is always executed irrespective of exceptions

    raise - The raise statement allows the programmer to force a specific exception to occur.
'''

dividend = float(input("Enter dividend "))
divisor = float(input("Enter divisor "))

#runs the code segment which may lead to error
try:
    result = dividend/divisor

#executed when there is an exception
except ZeroDivisionError:
    print("Divisor is Zero")

#executed when there is no exception
else:
    print(format(result,'.2f'))

#always executed
finally:
    print("End of Program")


'''
try:
    if divisor == 0:
        raise ZeroDivisionError()
except ZeroDivisionError:
    print("Divisor is zero")
else:
    result = dividend/divisor
    print(format(result, '.2f'))
finally:
    print("End of Program")
    
'''