#include <iostream>
// #define NDEBUG //g++ -NDEBUG
#include <cassert>


int main(int argc, char **argv)
{
    assert(argc == 2);
    std::cout << "This is an assert example." << std::endl;
    return 0;
}
