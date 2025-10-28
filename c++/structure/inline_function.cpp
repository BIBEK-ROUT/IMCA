#include<iostream>
using namespace std;
inline int square(int x) {
    return x*x;
}
int main()
{
    int data;
    cout<<"please enter the data:";
    cin>>data;
    cout<<"square of the number is:"<<square(data);
}