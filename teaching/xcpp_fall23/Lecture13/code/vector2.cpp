#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void load(std::vector<std::string> &v)
{
    v = {"Japan", "Italy", "Spain", "Egypt", "Chile", "Zaire", "Nepal", "Kenya"};
}

void print(const std::vector<std::string> &v)
{
    for (const auto &s : v)
        std::cout << s << std::endl;
    std::cout << std::endl;
}

int main()
{
    const int SIZE = 8;
    std::vector<std::string> v(SIZE);
    load(v);

    std::cout << "Original:" << std::endl;
    print(v);

    std::cout << "Reverse:" << std::endl;
    std::reverse(v.begin(), v.end());
    print(v);

    std::cout << "Sort:" << std::endl;
    std::sort(v.begin(), v.end());
    print(v);

    auto japanIt = std::find(v.begin(), v.end(), "Japan");
    if (japanIt != v.end())
    {
        std::cout << "Position of 'Japan': " << std::distance(v.begin(), japanIt) << std::endl;
        std::cout << "Position of 'Japan': " << japanIt - v.begin() << std::endl;
    }

    auto chinaIt = std::find(v.begin(), v.end(), "China");
    if (chinaIt != v.end())
    {
        std::cout << "Position of 'China': " << std::distance(v.begin(), chinaIt) << std::endl;
    }
    else
    {
        std::cout << "Not Found 'China'" << endl;
    }
}

