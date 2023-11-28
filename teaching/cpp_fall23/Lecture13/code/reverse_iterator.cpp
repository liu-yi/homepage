#include <list>
#include <iostream>
int main()
{
    std::list<int> c1 = {10, 20, 30};
    // c1.push_back(10);
    // c1.push_back(20);
    // c1.push_back(30);

    auto c1_rIter = c1.rbegin();

    std::cout << "The last element in the list is " << *c1_rIter << "." << std::endl;

    std::cout << "The list is:";
    for (auto c1_Iter = c1.begin(); c1_Iter != c1.end(); ++c1_Iter)
        std::cout << " " << *c1_Iter;
    std::cout << std::endl;

    // rbegin can be used to start an iteration through a list in reverse order
    std::cout << "The reversed list is:";
    for (auto c1_rIter = c1.rbegin(); c1_rIter != c1.rend(); ++c1_rIter)
        std::cout << " " << *c1_rIter;
    std::cout << std::endl;

    c1_rIter = c1.rbegin();
    *c1_rIter = 40;
    std::cout << "The last element in the list is now " << *c1_rIter << "." << std::endl;

    return 0;
}
