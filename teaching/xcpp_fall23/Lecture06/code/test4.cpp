#include <iostream>
using namespace std;

template <typename T>
T absolute(T x)
{
    cout << "The input type is " << typeid(T).name() << endl;

    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

int main()
{
    cout << absolute(1) << endl;
    cout << absolute(-1) << endl;
    cout << absolute(1.1f) << endl;
    cout << absolute(-1.1f) << endl;
    cout << absolute(1.1) << endl;
    cout << absolute(-1.1) << endl;
}