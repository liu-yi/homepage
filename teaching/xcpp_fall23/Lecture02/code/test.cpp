#include <iostream>

using namespace std;

int main()
{
    float f;
    double d = 123.456789e100;
    f = (float) d;
    cout << d << endl;
    cout << f << endl;
}