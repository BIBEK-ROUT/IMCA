class car:
    company="bmw"
    def getinput(self):
        self.model=input("Enter the model:")
        self.name=input("Enter the name:")
        self.version=float(input("Enter the version:"))
    def display(self):
        print("model is:",self.model)
        print("name is:",self.name)
        print("version is:",self.version)
        print("company is:",self.company)
ob1=car()
ob1.getinput()
ob1.display()
ob1.company="rollsroys"
ob1.name="ghost"
ob1.display()
ob2=car()
ob2.getinput()
ob2.display()
