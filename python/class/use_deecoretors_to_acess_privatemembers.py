class bankaccount:
    def __init__(self,owner,balance):
        self.owner=owner
        self.__balance=balance
    @property
    def balance(self):
        print(f"Balance is:{self.__balance}")
        return self.__balance
    @balance.setter
    def balance(self,amount):
        if amount>=0:
            self.__balance=amount
        else:
            print("Amount is invalid.")
class premimumAccount(bankaccount):
    def __init__(self,owner,balance):
        super().__init__(owner,balance)
    def upgrade(self,amount):
        print("old balance is:",self.balance)
        self.balance +=amount
        print("updated balance is:",self.balance)
ob1=premimumAccount("Bibek",1000)
amount=int(input("Enter the amount:"))
ob1.upgrade(amount)
    