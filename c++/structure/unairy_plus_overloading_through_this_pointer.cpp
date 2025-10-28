#include<iostream>
using namespace std;
struct vector2D
{
    int x,y;
    vector2D(const int& x,const int& y):x(x),y(y){}
 friend vector2D& operator+=( vector2D& other , vector2D& other1)
    {
        other.x += other1.x;
        other.y += other1.y;
        return other;
    }
    void show() const
    {
        cout << "Vector: (" << x << ", " << y << ")" << endl;
    }
};
int main()
{
    vector2D v1(3, 4);
    vector2D v2(1, 2);
    vector2D v3(5, 6);
    v1 += v2+=v3; // Chained addition using operator+=
    v1.show(); // Should show the result of (3+1+5, 4+2+6)
    return 0;
}