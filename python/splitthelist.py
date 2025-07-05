lis=input("please enter the elements in the list separated by the space:").split(" ")
print(lis)
k=int(input("please enter the no.of elements that the sub elment contains:"))
lis1=[]
for i in range(0,len(lis),k):
    lis1.append(lis[i:i+k])
print("The new list containg chunks of list is:",lis1)