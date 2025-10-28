#include<iostream>
using namespace std;
struct greet
{
    string name;
    greet()
    {
        cout<<"consturctor";
    }
    
    void show(string h1="hello")
    {
        cout<<"h1:"<<h1<<endl<<"name:"<<name<<endl;
    }
};
int main()
{
    greet ob1;
     ob1.name="bawal";
    ob1.show("gandu");
    return 0;
}