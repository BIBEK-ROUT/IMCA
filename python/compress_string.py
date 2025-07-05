from collections import OrderedDict
s1=input("please enter the string you want:")
def compress_string(s1):
    freq=OrderedDict()
    for ch in s1:
        freq[ch]=freq.get(ch,0)+1
    l3=[]
    for ch,count in freq.items():
        l3.append(ch)
        l3.append(str(count))
    s2="".join(l3)
    print(s2)
compress_string(s1)