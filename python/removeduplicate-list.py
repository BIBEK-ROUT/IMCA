lis=input("please enter element of the list separated by a space:").split(" ")
print(lis)
lis1=[]
for i in lis:
    if i in lis1:
        pass
    else:
        lis1.append(i)
del(lis[:])
print("list after removing duplicates:",lis1)