lis=list(map(int,input("please enter input in the list separated by space:").split(" ")))
i=0
lis1=[]
found=0
while(i<len(lis)):
    j=i
    lis1.append(lis[i])
    sum=0
    while(j<len(lis)):
        sum=sum+lis[j]
        j+=1
    i+=1
    sum1=sum(lis1)
    if sum1==sum:
        found=1
        break
if found==1:
    print("The equilibrium index of the list is:",i)
else:
    print("There is no equilibrium index in the list.")