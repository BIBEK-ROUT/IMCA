#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,5> p={1,2,3,4,5};
    for( auto &x:p)
    {
        x=x+1;
        
    }
    for(auto x:p)
    {
        cout<<x;
    }
    return 0;
}