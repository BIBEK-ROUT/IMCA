class employee:
    company="tokyo manji"
    def __init__(self):
        self.name=input("Enter the name:")
        self.id=input("Enter the id:")
        self.salary=int(input("Enter the salary:"))
        #self.company=input("Enter the name of the company:")
    def show(self):
        print("Name of the employee is:",self.name)
        print("Name of the id is:",self.id)
        print("The salary is:",self.salary)
        print("company name:",self.company)
    def rise_in_salary(self,x):
        add=self.salary*x/100
        self.salary=self.salary+add
ob1=employee()
ob1.show()
x=int(input("Enter the increase in salary:"))
ob1.rise_in_salary(x)
ob1.show()
ob2=employee()
ob2.show()
x=int(input("Enter the increase in salary:"))
ob2.rise_in_salary(x)
ob2.show()
