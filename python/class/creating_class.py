class person:
    company=""
    def __init__(self,company,name,address):
        self.company=company
        self.name=name
        self.address=address
        print("The intializer is called!")
    def show(self):
        print("Name of the company is:",self.company)
        print("Name of the person is:",self.name)
        print("The address is:",self.address)
ob1=person("Deloit","archana","bbsr")
ob1.show()
        