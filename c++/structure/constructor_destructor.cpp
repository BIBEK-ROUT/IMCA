/*#include<iostream>
using namespace std;
struct employee
{
    string name;
    string id;
    employee(const string& n,const string& i):name(n),id(i){
        cout<<"constructor called sucessfully!!";
    }
    ~employee()
    {
        cout<<"destructor worked sucessfully!!";
    }
};
int main()
{ 
    string id ,name;
    cout<<"Enter the name of the employee:";
    getline(cin,name);
    cout<<endl<<"Enter the id of the employee:";
    cin>>id;
    employee s(name,id);
    return 0;
}*/
#include<iostream>
using namespace std;

struct employee {
    string name;
    string id;
    employee(const string& n, const string& i) : name(n), id(i) {
        cout << "Constructor called successfully!!" << endl;
    }
    ~employee() {
        cout << "Destructor worked successfully!!" << endl;
    }
    void show()
    {
        cout<<"The employee name is:"<<name<<"his id:"<<id;
    }
};

int main() {
    string id, name;
    cout << "Enter the name of the employee: ";
    getline(cin, name);
    cout << "Enter the id of the employee: ";
    cin >> id;

    employee s(name, id);
    s.show();
    return 0;
}
