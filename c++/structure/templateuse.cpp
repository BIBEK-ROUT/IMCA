#include<iostream>
using namespace std;

template <typename T>
struct container;

template <typename T>
T show(const container<T>& b);

template<typename T>
struct container
{
    T value;

    // Constructor needed!
    container(T v) : value(v) {
        cout << "Constructor called!\n";
    }

    friend T show<T>(const container<T>& b);
};

template<typename T>
T show(const container<T>& b)
{
    cout << "Inside show(): ";
    cout << b.value << endl;
    return b.value;
}

int main()
{
    container<int> intval(90);
    show(intval);              
    return 0;
}
