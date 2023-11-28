#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <iterator>

int main()
{
    std::list<char> lst;

    // 使用随机数生成器生成随机字符，并插入到列表中
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('A', 'Z');

    for (int i = 0; i < 10; ++i)
        lst.push_back(static_cast<char>(dis(gen)));

    // 输出原始内容
    std::cout << "Original contents: ";
    for (const auto &elem : lst)
        std::cout << elem;

    std::cout << "\n";

    lst.sort();

    // 输出排序后的内容
    std::cout << "Sorted contents: ";
    for (const auto &elem : lst)
        std::cout << elem;

    return 0;
}
