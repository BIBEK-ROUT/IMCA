lis=list(map(int,input("please enter the list elements:").split(",")))
print(lis)
def sumavg(lis):
    sum=0
    for i in range(len(lis)):
        sum=sum+lis[i]
    avg=sum/len(lis)
    return sum,avg
print(sumavg(lis))
a,b=sumavg(lis)
print(a,b)
c=sumavg(lis)
print(c)



