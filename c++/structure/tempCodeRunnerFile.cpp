#include<iostream>
#include<cstdlib>
using namespace std;
class check
{
public:
    int data;
    check(const int &data):data(data)
    {
        cout<<"The constructor is called."<<endl;
    }
    ~check()
    {
        cout<<"Destructor is called."<<endl;
    }
    void show()
    {
        cout<<"The data passed is:"<<data<<endl;
    }
};
int main()
{
    int data;
    cout<<"Please enter the data:";
    cin>>data;
    check p(data);
    p.show();
    p.~check();
    exit(1);
    return 0;
}