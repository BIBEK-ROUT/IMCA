#include <iostream>
using namespace std;
class D{
    public:
    void show()
    {
        cout<<"show from class D"<<endl;
    }
};
class A:virtual public D {
public:
    void show() {
        cout << "Show from class A" << endl;
    }
};

class B:virtual public D{
public:
    void show() {
        cout << "Show from class B" << endl;
    }
};

class C : public A, public B {
    // Inherits show() from both A and B — ambiguous!
};

int main() {
    C obj;
    obj.show();  // ❌ Error: ambiguous!
    return 0;
}
