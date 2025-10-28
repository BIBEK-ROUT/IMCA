#include<iostream>
#include<array>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter the values for a and b:";
    cin>>a>>b;
    cout<<"\nsum="<<a+b;
    int arr[a];
    cout<<"\nEnter "<<a<<" elements for the array:";
    for(int i = 0; i < a; i++) {
        cin >> arr[i];
    }
    cout << "\nElements of the array are: ";
    for(int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }

    // Demonstrating C++ array vs C array

    // 1. Declaration
    // C-style array (size must be known at compile time)
    int cArr[5] = {1, 2, 3, 4, 5};

    // C++ STL array (std::array) - safer, size known at compile time
    array<int, 5> cppArr = {10, 20, 30, 40, 50};

    // 2. Initialization
    int cArr2[5] = {}; // All elements zero
    array<int, 5> cppArr2 = {}; // All elements zero

    // 3. Input (user input)
    cout << "\nEnter 5 elements for C-style array: ";
    for(int i = 0; i < 5; i++) {
        cin >> cArr[i];
    }
    cout << "Enter 5 elements for std::array: ";
    for(int i = 0; i < 5; i++) {
        cin >> cppArr[i];
    }

    // 4. Output
    cout << "C-style array: ";
    for(int i = 0; i < 5; i++) {
        cout << cArr[i] << " ";
    }
    cout << "\nstd::array: ";
    for(int x : cppArr) {
        cout << x << " ";
    }
    cout << endl;

    // 5. Functions available in std::array (not in C array)
    cout << "Size of std::array: " << cppArr.size() << endl;
    cout << "First element: " << cppArr.front() << endl;
    cout << "Last element: " << cppArr.back() << endl;
    cppArr.fill(100); // Set all elements to 100
    cout << "After fill(): ";
    for(int x : cppArr) cout << x << " ";
    cout << endl;

    // 6. Advantages of std::array over C array:
    // - Safer (bounds checking with at())
    // - Can use STL algorithms
    // - Supports assignment and comparison
    // - Size information available with size()
    // - Can be returned from functions

    // Example: bounds checking
    try {
        cout << "Accessing out of bounds: ";
        cout << cppArr.at(10) << endl; // Throws exception
    } catch(const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}