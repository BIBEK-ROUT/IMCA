class student:
    course="imca"
    def inputu(self):
        self.name=input("please enter the name:")
        self.mark=int(input("please enter  the marks:"))
    def display(self):
        print(self.name)
        print("the mark of the student is:",self.mark)
    def __gt__(self,s2):
        if self.mark>s2.mark:
            print("1st student ",self.mark)
        else:
            print("2nd student",s2.mark)
s1=student()
s1.inputu()
s1.display()
s2=student()
s2.inputu()
s1>s2