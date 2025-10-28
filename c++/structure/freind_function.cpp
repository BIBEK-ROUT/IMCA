#include<iostream>
using namespace std;
struct car{
    private:
    int engine_number;
    protected:
    string model;
    public:
    string name;
    car(int& e,string& m,string& n):engine_number(e),name(n),model(m)
    {
        cout<<"the car constructor is called!!";
    };
    friend  void show(car& a);
    ~car()
    {
        cout<<"the destructor of the car is called!!";
    };
};
void show(car& a)
{
        cout<<"car name is:"<<a.name<<"car model is:"<<a.model<<"car engine_number:"<<a.engine_number<<endl;
    };
int main()
{
    int engine_num;
    string model,name;
    cout<<"Enter the engine number of the car: ";
    cin>>engine_num;
    cout<<"Enter the model of the car: ";
    cin>>model;
    cout<<"Enter the name of the car: ";
    cin>>name;
    car c(engine_num, model, name);
    show(c);
    return 0;
}