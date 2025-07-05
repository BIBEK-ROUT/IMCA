str=input(r"please enter a string combination of {},[],():")
def check_validation(str):
    if(len(str)%2!=0):
        return False
    i=0
    found=0
    j=len(str)-1
    mid=(len(str)-1)//2
    if((ord(str[mid])==123 and ord(str[mid+1])==125) or (ord(str[mid])==40 and ord(str[mid+1])==41) or (ord(str[mid])==91 and ord(str[mid+1])==93)):
        return True
    if((ord(str[0])==123 and ord(str[j])==125) or (ord(str[0])==91 and ord(str[j])==93) or (ord(str[0])==40 and ord(str[j])==41)):
        k=1
        l=j-1
        while(k<=l):
            if(ord(str[k])==40 and ord(str[k+1])==41):
                pass
            elif(ord(str[k])==123 and ord(str[k+1])==125):
                pass
            elif(ord(str[k])==91 and ord(str[k+1])==93):
                pass
            else:
                found=1
                break
            k=k+2
        if found==0:
            return True
    while(i<j and j>i):
        if(ord(str[i])==40 and ord(str[j])==41):
            pass
        elif(ord(str[i])==123 and ord(str[j])==125):
            pass
        elif(ord(str[i])==91 and ord(str[j])==93):
            pass
        else:
            return False
        i+=1
        j-=1
    return True
value=check_validation(str)
if(value==True):
    print("The strings are valid parenthese.")
else:
    print("The strings are invalid parenthese.")
            