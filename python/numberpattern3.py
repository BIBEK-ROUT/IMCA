num=int(input("please enter the number you want:"))
for i in range(0,num):
    j=1
    while j<=i:
        print(" ",end="")
        j+=1
    for k in range(1,num-i+1):
        print(k,end="")
    print("\n")