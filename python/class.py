class student:
    def __init__(self,name,roll,mark):
        self.name1=name
        self.roll1=roll
        self.mark1=mark
    def display(self):
        print("the name of the student is:",self.name1)
        print("the roll.no of the student is:",self.roll1)
        print("the mark of the student is:",self.mark1)

name=input("please enter the name of the student:")
roll=input("please enter the roll.no of the student:")
mark=input("please enter the mark of the student:")
s1=student(name,roll,mark)
s1.display()
        