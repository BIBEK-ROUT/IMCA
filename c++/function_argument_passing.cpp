#include <iostream>
using namespace std;

// ✅ POINTER VERSION
// Accepts a pointer and modifies the original variable using dereferencing
namespace PointerVersion {
    void square(int* x) {
        *x = (*x) * (*x);
    }
}

// ✅ REFERENCE VERSION
// Accepts a reference and modifies the original variable directly
namespace ReferenceVersion {
    void square(int& x) {
        x = x * x;
    }
}

// ✅ VALUE VERSION
// Accepts a copy of the value and returns the squared result without modifying original
namespace ReturnVersion {
    int square(int x) {
        return x * x;
    }
}

int main() {
    int data;
    cout << "Enter the data to square: ";
    cin >> data;

    // ❌ PROBLEM (BEFORE): Using multiple overloads like
    // void square(int&), int square(int)
    // causes ambiguity when passing an int because both are valid matches:
    // - int can be passed by value (int)
    // - int can bind to a reference (int&)
    //
    // ⚠️ The compiler doesn’t use return type to choose the correct function.
    // So if we called: square(data); ← ERROR: ambiguous

    // ✅ SOLUTION: We use namespaces to separate each version.
    // This gives the compiler a fully qualified name with no ambiguity.

    // ✅ Pointer version — unambiguous via namespace
    PointerVersion::square(&data);
    cout << "Square using pointer: " << data << endl;

    // ✅ Reference version — also unambiguous
    ReferenceVersion::square(data);
    cout << "Square using reference: " << data << endl;

    // ✅ Return value version — again clear
    cout << "Square using return value: " << ReturnVersion::square(data) << endl;

    return 0;
}
