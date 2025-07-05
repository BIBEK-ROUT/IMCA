num=int(input("please enter a number you want:"))
if(num<=0):
    print("invalid number.")
count=0
for i in range(1,num):
    if num%i==0:
        count+=1
if(count>1):
    print("the number is not a prinme number.")        
else:
    print("the number is a prime number.")