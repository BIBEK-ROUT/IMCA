#include<iostream>
using namespace std;
class counter
{
    int x;
    static int count;
    counter(int x=0):x(x){
        cout<<"constructor is called!!";
    }
    public:
    static counter increment(int data)
    {
        count++;
        return counter(data);
    }
    static void getvalue()
    {
        cout<<"The no.of objects created are:"<<count;
    }
    void show()
    {
        cout<<"The value passed is:"<<x;
    }
};
int counter::count = 0;
int main()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    counter s=counter::increment(data);
    s.getvalue();//counter::getvalue()
    s.show();
    counter d=counter::increment(data);
    d.getvalue();//counter::getvalue();
    d.show();
    return 0;
}