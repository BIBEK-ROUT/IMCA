num=int(input("please enter the range of the sereis:"))
a=0
b=1
print("displaying the series:")
for i in range(1,num+1):
    print(a,end="")
    sum=a+b
    a=b
    b=sum
    