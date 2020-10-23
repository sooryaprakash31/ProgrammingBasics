

dividend = float(input("Enter dividend "))
divisor = float(input("Enter divisor "))

try:
    result = dividend/divisor
except ZeroDivisionError:
    print("Divisor is Zero")
else:
    print(format(result,'.2f'))
finally:
    print("End of program")