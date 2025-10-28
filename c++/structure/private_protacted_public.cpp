#include<iostream>
using namespace std;
struct person{
    private:
    int salary;
    protected:
    string name;
    int age;
    public:
    person(string& n,int& a,int& s) : name(n), age(a), salary(s) {
        cout << "Default constructor called!" << endl;
    } // Default constructor

     void show()
    {
        cout<<"The name of the person is "<<name<<" and his age is "<<age<<",he earns:"<<salary<<"per month."<<endl;

    }
};
struct employee: public person  // Inheriting from person
{
    int room_no;
    // This code is inaccessible because 'name', 'age', and 'salary' are private/protected members of 'person'.
    // You cannot directly initialize them in the member initializer list of 'employee' like this.
    // Only the base class constructor can initialize these members.
    // Instead, you should call the base class constructor in the initializer list:

    employee(int r, string n, int a, int s) : person(n,a,s), room_no(r) {
        //name = n;      // 'name' is protected, so accessible here
       // age = a;       // 'age' is protected, so accessible here
        // salary is private in 'person', so NOT accessible here
        //salary = s;  // This will cause a compilation error
    }
 void show()
    {
        cout<<"The employee name is:"<<name<<" his age is:"<<age<<" and his room number is:"<<room_no<<endl;
        person::show(); // Call the base class show method to display name and age
    }
};
int main()
{
    employee e(101, "John", 30, 5000);
    e.show(); // Assuming you have a constructor that takes these parameters
    return 0;
}