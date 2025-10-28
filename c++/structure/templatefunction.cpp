#include<iostream>
using namespace std;
template<typename T,typename U,typename V>
void fun(T a,U b,V c)
{
    cout<<"a="<<a<<"b="<<b<<"c="<<c<<endl;
}
int main()
{
    fun("hello ji",3,9.1);
    return 0;
}
