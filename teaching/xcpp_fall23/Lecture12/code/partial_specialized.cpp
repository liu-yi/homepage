#include <iostream>
using namespace std;
template <typename T1, typename T2>
class Data
{
private:
    T1 a;
    T2 b;

public:
    Data(T1 m, T2 n) : a(m), b(n)
    {
        cout << "Original class templete Data<T1, T2>" << endl;
    }
    void display()
    {
        std::cout << " Original class templete Data: " << a << ", " << b << std::endl;
    }
};

template <typename T1>
class Data<T1, char>
{
private:
    T1 a;
    char b;

public:
    Data(T1 m, char c) : a(m), b(c)
    {
        cout << "Partial specialization class templete Data<T1, char>" << endl;
    }
    void display()
    {
        std::cout << " Partial specialization class templete Data: " << a << ", " << b << std::endl;
    }
};

int main()
{
    Data<int, int> d_original(5, 8);
    d_original.display();

    Data<double, char> d_special(3.4, 'A');
    d_special.display();
}
