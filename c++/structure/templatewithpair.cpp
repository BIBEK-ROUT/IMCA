#include<iostream>
using namespace std;
template<typename T,typename V>
struct templatewithpair
{
    T a;
    V b;
    templatewithpair(const pair<T,V>&p):a(p.first),b(p.second)
    {
        cout<<"constructor called sucessfully!";
    }
    void display()
    {
        cout<<"a:"<<a<<" b:"<<b;
    }
};
int main()
{
    pair<string,int> p=make_pair("Bhai",1);
    templatewithpair<string,int>student(p);
    student.display();
}