#include <iostream>
#include <array>

int main()
{
    // 创建一个包含5个整数的std::array
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    // 输出数组的元素
    std::cout << "Array elements: ";
    for (int element : myArray)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 修改数组的元素
    myArray[2] = 10;

    // 再次输出修改后的数组
    std::cout << "Updated array elements: ";
    for (int element : myArray)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
