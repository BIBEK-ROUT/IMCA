#include <iostream>
using namespace std;

struct Person {
    string name;

    // Constructor
    Person(const string& n) : name(n) {
        cout << "Constructor called for " << name << "\n";
    }

    // Destructor
    ~Person() {
        cout << "Destructor called for " << name << "\n";
    }

    void greet() {
        cout << "Hello, I am " << name << "\n";
    }
};

int main() {
    Person p("Alice");
    p.greet();
    p.~Person();
    return 0;
}
