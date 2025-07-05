num=int(input("please enter the no.of lines you want:"))
for i in range(1,num+1):
    for j in range(1,num-i+1):
        print(" ",end="")
    for k in range(1,i+1):
        print(chr(k+64),end="")
    if(i!=1):
        for l in range(i-1,0,-1):
            print(chr(l+64),end="")
    print("\n")
