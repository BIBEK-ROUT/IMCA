lis=list(input("please enter the strings separated by space:").split(" "))
def check_anagrams(lis):
    result=[]
    used=[False]*len(lis) #keep the record which word are used
    for i in range(len(lis)):
        if used[i]:
            continue
        group=[lis[i]]  #adds the element which is used for comparing
        used[i]=True
        for j in range(i+1,len(lis)):#compare with the rest
            if(used[j]!=True and sorted(lis[i])==sorted(lis[j])):
                group.append(lis[j])
                used[j]=True #mark as used
        result.append(group)#add the group to result
    print("Anagrams group:")
    for group in result:
        print(group)
"""from collections import defaultdict #comment out and use this one if you the input is too big
def check_anagrams(lis1):
    groups = defaultdict(list)
    for word in lis1:
        key = tuple(sorted(word))
        groups[key].append(word)

    print("Anagram groups:")
    for group in groups.values():
        print(group) """
check_anagrams(lis)
