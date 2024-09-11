#include <iostream>
#include <fstream>
#include <stdexcept>

class CustomException : public std::exception
{
public:
    const char *what() const noexcept
    {
        return "This is a custom exception";
    }
};

void exampleMultipleExceptionTypes(int divisor)
{
    try
    {
        if (divisor == 0)
        {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        // 模拟抛出一个异常
        throw std::runtime_error("An exception occurred");
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    catch (...)
    {
        // 捕获其他类型的异常
        std::cerr << "An unexpected exception occurred" << std::endl;
    }
}

void exampleExceptionHandling()
{
    try
    {
        // 示例1：基本异常处理
        throw std::runtime_error("A basic exception occurred");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught basic exception: " << e.what() << std::endl;
    }

    try
    {
        // 示例2：多个异常类型
        exampleMultipleExceptionTypes(0);
    }
    catch (...)
    {
        // 处理其他异常
        std::cerr << "An unexpected exception occurred" << std::endl;
    }

    try
    {
        // 示例3：自定义异常类
        throw CustomException();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught custom exception: " << e.what() << std::endl;
    }
}

int main()
{
    exampleExceptionHandling();

    return 0;
}
