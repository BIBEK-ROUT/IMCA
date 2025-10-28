#include<iostream>
using namespace std;
class demo
{
    public:
    int data;
    demo(const int& d):data(d)
    {
        cout<<"constructor of demo is called sucessfully!!"<<endl;
    }
    demo(const demo& source)
    {
        data=source.data;
        cout<<"copy constructor called!!";
    }
};
int main()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    demo ob1(data);
    demo ob2(ob1);
    return 0;
}