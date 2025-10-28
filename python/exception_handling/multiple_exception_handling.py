import sys
num1=int(input("Enter the number:"))
num2=int(input("Enter the number:"))
try:
    div=num1/num
except Exception :
    print("Something exploded:", sys.exc_info()[1])
    print(sys.exc_info()[0])
else:
    print('h')
finally:
    print("rest in piece.")
