class demo:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def __eq__(self, value):
        print("operator is overloaded.")
        return demo(self.x==value.x , self.y==value.y)
ob1=demo(2,3)
ob2=demo(4,5)
ob3=ob1==ob2
print(ob3.x,ob3.y)
    