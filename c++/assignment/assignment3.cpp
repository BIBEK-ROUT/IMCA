#include<iostream>
using namespace std;
class dynamic
{
    public:
    int data;
    dynamic(const int& data)
    {
        this->data=data;
        cout<<"constructor of dynamic is called!!"<<endl;
    }
    void show()
    {
        cout<<"data="<<data;
    }
};
int main()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    dynamic *s=new dynamic(data);
    s->show();
}