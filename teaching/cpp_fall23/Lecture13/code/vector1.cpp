#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::vector<char> v;

    // 向向量中插入值
    for (int i = 0; i < 10; ++i)
        v.push_back('J' - i);

    // 使用下标访问向量内容
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    // 使用迭代器访问向量内容
    for (auto p = v.begin(); p != v.end(); ++p)
        std::cout << *p << " ";
    std::cout << std::endl;

    // 使用范围循环访问向量内容
    for (auto p : v)
        std::cout << p << " ";
    std::cout << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    // std::vector<int> numbers(5, 99); // 创建包含5个元素，每个元素初始化为99

    // std::array<int, 5> arr = {1, 2, 3, 4, 5};
    // std::vector<int> numbers(arr.begin(), arr.end());

    // 在尾部插入元素
    numbers.push_back(6);

    // 访问元素
    std::cout << "Elements: ";
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 修改元素
    numbers[2] = 10;

    // 获取大小
    std::cout << "Size: " << numbers.size() << std::endl;

    // 删除最后一个元素
    numbers.pop_back();

    std::cout << "Size: " << numbers.size() << std::endl;
}
