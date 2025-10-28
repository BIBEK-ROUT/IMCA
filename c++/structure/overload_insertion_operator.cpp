#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;

    // Friend function inside struct
    friend ostream& operator<<(ostream& out, const Person& p);
};

ostream& operator<<(ostream& out, const Person& p) {
    out << "Name: " << p.name << ", Age: " << p.age;
    return out;
}

int main() {
    Person p = {"Bibek", 25};
    cout << p << endl;
    return 0;
}
