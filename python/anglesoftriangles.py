import math
a,b,c=map(int,input("please enter the sides of a triangle separated by space:").split(" "))
print("The 3 sides of the traingle are:",a,b,c)
def check(a,b,c):
    if(a+b<=c or a+c<=b or b+c<a):
        print("This is not a triangle,please reenter the sides:")
        exit(1)
def find_angles(a,b,c):
    check(a,b,c)
    d=(b*b+c*c-a*a)/(2*b*c)
    e=(a*a+c*c-b*b)/(2*a*c)
    f=(a*a+b*b-c*c)/(2*a*b)
    A=round(math.degrees(math.acos(d)))
    B=round(math.degrees(math.acos(e)))
    C=round(math.degrees(math.acos(f)))
    print("angle of A is:",A)
    print("angle of B is",B)
    print("angle of C is:",C)
find_angles(a,b,c)
    
        