try:
    age=int(input("please enter the age:"))
    if(age<0):
        raise ValueError
    print("your age is:",age)
except ValueError as var:
    print("Enter valid age.")
try:
    age=int(input("please enter the age:"))
    if(age<0):
        raise ValueError("INVALID AGAIN.")
    print("your age is:",age)
except ValueError as var:
    print(var)