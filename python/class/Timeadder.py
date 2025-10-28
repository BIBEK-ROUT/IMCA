class Time:
    def __init__(self,hour,min,sec):
        self.hour=hour
        self.min=min
        self.sec=sec
    def __add__(self,ob1):
        ob = Time(0, 0, 0)
        ob.hour = self.hour + ob1.hour
        ob.min=self.min+ob1.min
        ob.sec=self.sec+ob1.sec
        return ob
    def display(self):
        if(self.sec>60):
            temp1=self.sec//60
            self.min=self.min+temp1
            self.sec=self.sec%60
        if(self.min>60):
            temp1=self.min//60
            self.hour=self.hour+temp1
            self.min=self.min%60
        print(self.hour,',',self.min,',',self.sec)
ob1=Time(3,4,890)
ob2=Time(3,4,890)
ob=ob1+ob2
ob1.display()
ob2.display()
ob.display()

