class A:
    def __init__(self):
        print("Class A constructor called")
class B(A):
    def __init__(self):
        super().__init__()
        print("Class B constructor called")
class C(A):
    def __init__(self):
        super().__init__()
        print("Class C constructor called")
class D(B, C):
    def __init__(self):
        super().__init__()
        print("Class D constructor called")
class E(D):
    def __init__(self):
        super().__init__()
        print("Class E constructor called")
class F(E):
    def __init__(self):
        super().__init__()
        print("Class F constructor called")
ob1 = F()
print("Object of class F created successfully")