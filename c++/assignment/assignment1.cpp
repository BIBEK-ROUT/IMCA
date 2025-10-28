#include<iostream>
using namespace std;
class largest
{
    public:
    int a,b,c;
    largest(const int& a,const int& b,const int& c):a(a),b(b),c(c)
    {
        cout<<"constructor of largest is called sucessfully."<<endl;
    }
    void find_largest()
    {
        if(a>b && a>c)
            cout<<"The largest value is:"<<a;
        else if(b>a && b>c)
            cout<<"The largest value is:"<<b;
        else
            cout<<"The largest value is:"<<c;
    }
};
int main()
{
    int a,b,c;
    cout<<"Enter the value of a,b,c:";
    cin>>a>>b>>c;
    largest ob1(a,b,c);
    ob1.find_largest();
    return 0;
}