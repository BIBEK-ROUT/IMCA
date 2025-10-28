#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    std::vector<int>nums={1,2,3,4};
    int factor =3;
    std::for_each(nums.begin(),nums.end(),[factor](int &x){ 
        if(x%2==0)
        cout<<"This is even:"<<x;
        x*=factor;
     });
     for(int &num:nums)
     {
        cout<<num;
     }
}