import random
word_length=int(input("please enter a the no.of letters in a password:"))
lis=['a','1','b','*','&','c']
random.seed(1)
print([random.choice(lis) for i in lis ])

'''random.seed(5)  # Reset seed
print([random.randint(1, 10) for _ in range(5)])  # Exactly same list'''
