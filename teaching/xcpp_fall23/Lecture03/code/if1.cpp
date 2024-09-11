#include <iostream>
using namespace std;

int main()
{
    int *p = new int[1024];
    if (!p)
        cout << "Memory allocation failed." << endl;
    else
    {
        cout << "Memory has been allocated." << endl;
    }
    return 0;
}