#include <iostream>
#include <utility>

int main()
{
    // 创建一个pair，包含一个整数和一个字符串
    std::pair<int, std::string> myPair = std::make_pair(42, "Hello, Pair!");

    // 访问pair的元素
    std::cout << "Pair: (" << myPair.first << ", " << myPair.second << ")" << std::endl;

    // 修改pair的元素
    myPair.first = 99;
    myPair.second = "Updated Pair!";

    // 再次访问pair的元素
    std::cout << "Updated Pair: (" << myPair.first << ", " << myPair.second << ")" << std::endl;

    return 0;
}
