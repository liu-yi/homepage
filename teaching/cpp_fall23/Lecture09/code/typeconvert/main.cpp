#include <iostream>
#include "time.hpp"

using namespace std;

int main()
{
    MyTime t1(1, 20);
    int minutes = t1;    // implicit conversion
    float f = float(t1); // explicit conversion.
    float f1 = t1;       // what about this?
    std::cout << "minutes = " << minutes << std::endl;
    std::cout << "minutes = " << f << std::endl;
    std::cout << "minutes = " << f1 << std::endl;

    MyTime t2 = 70;
    std::cout << "t2 is " << t2 << std::endl;

    MyTime t3;
    t3 = 80;
    std::cout << "t3 is " << t3 << std::endl;

    return 0;
}
