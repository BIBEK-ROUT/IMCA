class a:
    def show(self):
        print("class a show.")
class b:
    def show(self):
        super().show()
        print("class b show.")
class c(b,a):
    def show(self):
        super().show()
        print("class c show.")
ob1=c()
ob1.show()