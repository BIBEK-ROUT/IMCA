class bank:
    name="RBI"
    def show(self):
        print("Bank name:",self.name)
class savingaccount(bank):
    def __init__(self,name,accountno):
        self.name=name
        self.accountno=accountno
    def show(self):
        print("Bank name:",self.name)
        print("account number:",self.accountno)
class currentaccount(bank):
    def __init__(self,name,accountno):
        self.name=name
        self.accountno=accountno
    def show(self):
        print("Bank name:",self.name)
        print("account number:",self.accountno)
ob1=savingaccount("HDFC",123)
ob1.show()
ob2=currentaccount("AXIS",124)
ob2.show()
        
        