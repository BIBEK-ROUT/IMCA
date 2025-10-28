#include <iostream>
using namespace std;

struct shape {
    virtual void show() {
        cout << "shape is drawn.";
    }
};

struct circle : shape {
    void show() override {
        cout << "circle is drawn.";
    }
};

struct rectangle : shape {
    void show() override {
        cout << "rectangle is drawn.";
    }
};

int main() {
    shape* s1[2];
    s1[0] = new circle();
    s1[1] = new rectangle();

    for (int i = 0; i < 3; ++i) {
        s1[i]->show();
        cout << endl;
        delete s1[i]; // Clean up memory
    }
}