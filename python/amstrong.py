import math 
n=int(input("please enter the number you want to check:"))
count=0
num=n
while num!=0:
    dig=num%10
    count+=1
    num=num//10
print("the numbers of digits in the number is:",count)    
sum=0
num=n
while num!=0:
    dig=num%10
    sum=sum+pow(dig,count)
    num//=10
if(sum==n):
    print("the number is a amstrong number.")
else:
    print("the number is not a amstrong number.")

