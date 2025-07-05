s1=input("please enter a substring you want to check:")
s2=input("please enter another substring you want to check:")
def  check_rotation(s1,s2):
    l1=list(s1)
    l3=[]
    length=len(l1)
    j=i=len(s1)-1
    while (j>=0):
        l1.insert(0,l1[i])
        l1.pop(i+1)
        x=''.join(l1)
        print(x)
        l3.append(x)
        j-=1
    print(l3)
    if s2 in l3:
        print("it is the rotation of s1 string.")
    else:
        print("it is not the rotation of s1 string.")
check_rotation(s1,s2)