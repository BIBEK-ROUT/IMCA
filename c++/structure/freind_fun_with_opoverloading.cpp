#include<iostream>
using namespace std;

struct complex {
private:
    int a, b; // These are the real and imaginary parts, kept private to enforce encapsulation (good OOP practice)

    // 🔐 Constructor is private — so we can’t directly create objects from outside the class.
    // We use `int a, int b` (by value) instead of `const int& a` because:
    //  - For simple types like int, pass-by-value is actually more efficient (no indirection).
    //  - And more importantly: we can pass **temporaries** like 3 or 4.
    //    `const int&` would also work, but it's unnecessary overhead for basic types like int.
    complex(int a, int b) : a(a), b(b) {
        cout << "The complex constructor is called!!" << endl;
    }

public:
    // 🏭 Static Factory Function — why do we use this?
    //  - Because the constructor is private, we can't write `complex a(3,4);` in main.
    //  - So we create this static `create()` function to allow object creation in a controlled way.
    static complex create(int a, int b) {
        return complex(a, b);  // Calls the private constructor from within the class — allowed.
    }

    // ➕ Friend Function for Operator Overloading
    //  - Needs to be a friend to access private members `a` and `b`.
    //  - We pass by `const reference` to avoid copying (efficient).
    friend complex operator+(const complex& c1, const complex& c2);

    // 🎭 A helper function to show values — added as per your request
    void show() const {
        cout << a << " + " << b << "i" << endl;
    }

    // 💥 Destructor to show when objects are destroyed
    ~complex() {
        cout << "The complex destructor is called!!" << endl;
    }
};

// 🧮 Overloaded + operator (outside the struct)
//    - We use `const complex&` for performance (avoids copying)
//    - We return a new complex number: sum of real and imaginary parts.
complex operator+(const complex& c1, const complex& c2) {
    return complex(c1.a + c2.a, c1.b + c2.b);
}

int main() {
    // ✨ Object creation using static factory
    complex a = complex::create(3, 4);
    complex b = complex::create(4, 5);

    // ➕ Operator overloading in action
    complex c = a + b;

    // 👀 Show result
    cout << "Result of a + b: ";
    c.show();

    return 0;
}
