#include<iostream>
using namespace std;
using cal= class calculator
{
    int value;
    public:
    calculator(int v=0):value(v)
    {
        cout<<"constructor called."<<endl;
    }
    void add(int x)
    {
        value+=x;
    }
    void multiply(int x)
    {
        value*=x;
    }
    void show()
    {
        cout<<"The vlaue is:"<<value;
    }
};
int main()
{
    cal ob(1);
    ob.add(2);
    ob.multiply(3);
    ob.show();
    return 0;
}