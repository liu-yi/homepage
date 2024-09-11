#include <set>
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::cout << "Using set: " << std::endl;

    std::set<std::string> source_set;
    std::string input;

    while (std::cin >> input)
    {
        source_set.insert(input);
    }

    std::cout << std::endl;

    for (const std::string &s : source_set)
    {
        std::cout << s << std::endl;
    }

    std::cout << "Using multiset: " << std::endl;

    std::multiset<std::string> source_multiset;
    std::cin.clear();

    while (std::cin >> input)
    {
        source_multiset.insert(input);
    }

    std::cout << std::endl;

    for (const auto &s : source_multiset)
    {
        std::cout << s << std::endl;
    }

    return 0;
}
