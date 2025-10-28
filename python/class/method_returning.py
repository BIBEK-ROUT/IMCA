class methods:
    def __init__(self,data):
        self.data=data
    def increment(self):
        self.data+=1
        print("get incremented.")
        return self
    def display(self):
        print("data:",self.data)
        return self
ob1=methods(0)
ob1.increment().display().increment().display()