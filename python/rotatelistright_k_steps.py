lis=input("please enter the elements of the list separated by a space:").split(" ")
k=int(input("please enter no.of times you want to rotate the elelments of the list:"))
for i in range(k):
    lis.insert(0,lis[len(lis)-1])
    lis.pop(len(lis)-1)
print(lis)