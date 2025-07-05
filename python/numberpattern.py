num=int(input("please entr the no.of lines you want:"))
a=0
for i in range(1,num+1):
    if i%2==0:
        j=1
        while j<=i:
            j+=1
            a=a+1
            print(a,end="")
    if i%2!=0:
        j=1
        k=a+i
        a=a+i
        while j<=i:
            print(a,end="")
            a=a-1
            j+=1
        a=k
    print("\n")