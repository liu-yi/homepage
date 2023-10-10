#include <iostream>
using namespace std;

int num_chain(int n)
{
    // cout << n << endl;
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 1 + num_chain(n / 2);
    }
    else
    {
        return 1 + num_chain(3 * n + 1);
    }
}

int main()
{
    for (int i = 90; i <= 100; i++)
    {
        int chain_len = num_chain(i);
        cout << i << " chain_num = " << chain_len << endl;
    }
}