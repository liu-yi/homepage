#include <iostream>

class ResourceHandler
{
public:
    ResourceHandler()
    {
        // 在构造函数中进行资源的获取
        std::cout << "Resource acquired" << std::endl;
    }

    ~ResourceHandler()
    {
        // 在析构函数中进行资源的释放
        std::cout << "Resource released" << std::endl;
    }
};

void example()
{
    ResourceHandler resource; // 在对象作用域内，构造函数获取资源

    // 假设在这里发生了异常
    throw std::runtime_error("An exception occurred");
    // 无论异常是否发生，对象离开作用域时，析构函数都会被调用，确保资源被释放
}

int main()
{
    try
    {
        example();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}