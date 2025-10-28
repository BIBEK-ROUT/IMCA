class Fivedivisonerror(Exception):
    def __init__(self):
        print("Division by 5 is not allowed.")
    pass
try:
    age=int(input("Please enter the age:"))
    num=int(input("please enter the num to divide:"))
    result=age/num
    if(num==5):
        raise Fivedivisonerror
except (Fivedivisonerror,ZeroDivisionError) as obj:
    print(obj)