#include <iostream>
using namespace std;

class Base
{
protected:
    int n;

private:
    int x = 1;

public:
    Base(int n) : n(n) {}

    int getN()
    {
        return n;
    }

    void foo1(Base &b)
    {
        n++;   // Okay
        b.n++; // Okay
    }

    int getX(Base &b)
    {
        return b.x;
    }
};

class Derived : public Base
{
public:
    Derived(int n) : Base(n) {}
    void foo2(Base &b, Derived &d)
    {
        n++;       // Okay
        this->n++; // Okay
        // b.n++;      //Error. You cannot access a protected member through base
        d.n++; // Okay
    }
};

void compare(Base &b, Derived &d) // a non-member non-friend function
{
    // b.n++; // Error
    // d.n++; // Error
}

int main()
{
    Base b(1);
    cout << b.getN() << endl;
}