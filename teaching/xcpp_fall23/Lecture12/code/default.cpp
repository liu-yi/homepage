#include <iostream>
using namespace std;

class B
{
public:
    int b;
    // B() = default;
    B(int b)
    {
        this->b = b;
    }
};

int main()
{
    B b1;
    B b2(2);
    cout << b1.b << endl;
    cout << b2.b << endl;
}
