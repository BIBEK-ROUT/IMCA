#include<iostream>
using namespace std;
class num
{
    public:
    int data;
    num(const int& data):data(data)
    {
        cout<<"constructor of num is called!!"<<endl;
    }
    ~num()
    {
        cout<<"Destructor is called!!";
    }
};
int main()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    num ob1(data);
    ob1.~num();
}