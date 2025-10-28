#include<iostream>
using namespace std;
struct operators
{
    public:
    int a,b;
    operators(const int& a,const int& b):a(a),b(b)
    {
        cout<<"The operators constructors is called:";
    }
    operators operator+(const operators& c2)   
    {
        return operators(a+c2.a,b+c2.b);
    }
    operators operator-(const operators& c2)   
    {
        return operators(a-c2.a,b-c2.b);
    }
    operators operator*(const operators& c2)   
    {
        return operators(a*c2.a,b*c2.b);
    }
    operators operator/(const operators& c2)   
    {
        if(c2.a == 0 || c2.b == 0) {
            cout << "Error: Division by zero!" << endl;
            return operators(0, 0); // Return a default object to avoid undefined behavior
        }
        return operators(a/c2.a,b/c2.b);
    }
    ~operators()
    {
         cout<<"The destructor operator is called";
    }
};
int main()
{
    int a,b;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter the second number: ";
    cin>>b;
    operators op1(a, b);
    operators op2(2, 3); // Example second operator object
    operators op3(0, 1); // Default object for division by zero handling
    operators result_add = op1 + op2+op3;//chain addition
    operators result_sub = op1 - op2;
    operators result_mul = op1 * op2;
    operators result_div = op1 / op2;
    cout << "Addition Result: " << result_add.a << ", " << result_add.b << endl;
    cout << "Subtraction Result: " << result_sub.a << ", " << result_sub.b << endl;
    cout << "Multiplication Result: " << result_mul.a << ", " << result_mul.b << endl;
    cout << "Division Result: " << result_div.a << ", " << result_div.b << endl;
    return 0;
}