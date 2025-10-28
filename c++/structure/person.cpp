#include<iostream>
using namespace std;
struct person{
    string name;
    int age;
    void show()
    {
        cout<<"The name of the person is "<<name<<" and his age is "<<age<<endl;
    }
};
int main()
{
    person s;
    cout<<"Enter the name of the person:";
    cin>>s.name;
    cout<<"Enter the age of the person:";
    cin>>s.age;
    s.show();
    return 0;
}