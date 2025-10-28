#include<iostream>
using namespace std;
class secret {
    int x;
    secret(int x=0):x(x)
    {
        cout<<"constructor is called!!"<<endl;
    }
    public:
    static secret create(int data)
    {
        return secret(data);
    }
    void show()
    {
        cout<<"The value of private member x is:"<<x;
    }
};
int main()
{
    int data;
    cout<<"Enter the data:";
    cin>>data;
    secret s=secret::create(data);
    s.show();
    return 0;
}