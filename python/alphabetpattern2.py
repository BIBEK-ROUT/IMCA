num=int(input("please enter the no.of lines you want:"))
for i in range(0,num):
    for j in range(0,i):
        print(" ",end="")
    for k in range(1,num-i+1):
        print(chr(k+64),end="")
    if(i!=num):
        for j in range(num-i-1,0,-1):
            print(chr(j+64),end="")
    print("\n")