#include <iostream>
#include <stdexcept>

class DivideByZeroException : public std::runtime_error
{
public:
    DivideByZeroException(const std::string &message) : std::runtime_error(message) {}
};

double divideNumbers(int numerator, int denominator)
{
    if (denominator == 0)
    {
        // 除数为零，抛出 DivideByZeroException 异常
        throw DivideByZeroException("Division by zero");
    }

    return static_cast<double>(numerator) / denominator;
}

int main()
{
    try
    {
        double result = divideNumbers(10, 2);
        std::cout << "Result: " << result << std::endl;

        result = divideNumbers(5, 0);                   // 除数为零，抛出异常
        std::cout << "Result: " << result << std::endl; // 不会执行到这里
    }
    catch (const DivideByZeroException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl; // 输出 "Division by zero"
    }

    return 0;
}
