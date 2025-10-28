class acc:
    def __init__(self, owner, balance):
        self.owner = owner              # ✅ Public attribute
        self.__balance = balance        # ✅ Private attribute using name mangling

    # ✅ Public method to safely deposit money
    def deposite(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"Deposited {amount}")
            print(f"Current balance: {self.__balance}")
        else:
            print("Deposit amount must be positive.")

    # ✅ Public method to safely withdraw money
    def withdrawl(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            print(f"Amount withdrawn: {amount}")
            print(f"Amount left: {self.__balance}")
        else:
            print("Insufficient balance.")

    # ✅ Getter method to access private balance safely
    def get_balnce(self):
        print("Account balance is:", self.__balance)
        return self.__balance


# Creating an object
ob1 = acc("Bibek Rout", 3000000)

# Using methods to interact with private data
ob1.deposite(40000000)
ob1.withdrawl(1000000)
print(f"Balance is: {ob1.get_balnce()}")
print("Owner is:", ob1.owner)  # Public attribute accessed directly
