#include<iostream>
using namespace std;
class Calculator {
    int val;
public:
    // ✅ Single constructor with default argument
    Calculator(int v = 0) : val(v) {}

    Calculator& add(int x) {
        val += x;
        return *this;
    }

    Calculator& multiply(int x) {
        val *= x;
        return *this;
    }

    void show() {
        cout << "The value is: " << val << endl;
    }
};
int main() {
    Calculator a(7);        // uses default value 0
    a.add(5).multiply(2).show();  // (0 + 5) * 2 = 10

    Calculator b(3);     // uses value 3
    b.add(2).multiply(4).show();  // (3 + 2) * 4 = 20

    return 0;
}

