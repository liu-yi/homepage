#include <iostream>
using namespace std;
template <typename T1, typename T2, typename V = char>
class A
{
private:
    T1 a;
    T2 b;
    V c;

public:
    A(T1 x, T2 y, V z) : a(x), b(y), c(z) {}
    void display()
    {
        cout << "a = " << a << endl; 
        cout << "b = " << b << endl; 
        cout << "c = " << c << endl; 
    }
};

int main()
{
    A<int, float> d(5, 6.5, 'c');
    d.display();

    A<int, char, bool> e(5, 'a', true);
    e.display();
    return 0;
}
