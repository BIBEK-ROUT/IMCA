class person:
    name="ha"
    age=18
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print("name is:", self.name)
        print("age is:", self.age)

class man(person):
    def __init__(self, name, age, salary):
        person.__init__(self,name, age)
        self.salary = salary

    def show(self):
        super().show()
        # person.show(self)  # Alternative way to call the parent class method
        print("salary is:", self.salary)
        print("name is:", self.name)
        print("age is:", self.age)

ob1 = person("bibek", 18)
#ob1.show()
ob2 = man("bibek", 18, 9000000)
ob2.show()