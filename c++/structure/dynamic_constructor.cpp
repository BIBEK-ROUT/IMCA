#include<iostream>
#include<string.h>
using namespace std;
class overload
{
    public:
    char *ch;
    overload(char * data)
    {
        ch=new char[strlen(data)+1];
        strcpy(ch,data);
        cout<<"constructor is called."<<endl;
    }
    void show()
    {
        cout<<"The value of x is:"<<ch;
    }
};
int main()
{
    char ch[50];
    cin.getline(ch,50);
    cin>>ch;
    overload p(ch);
    p.show();
}