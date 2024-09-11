#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class FileHandler
{
public:
    // 构造函数负责打开文件
    explicit FileHandler(const std::string &filename) : file(filename)
    {
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file");
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    // 析构函数负责关闭文件
    ~FileHandler()
    {
        file.close();
        std::cout << "File closed" << std::endl;
    }

    // 写入数据到文件
    void writeToFile(const std::string &data)
    {
        if (!file.is_open())
        {
            throw std::logic_error("File is not open");
        }
        file << data;
        std::cout << "Data written to file" << std::endl;
    }

private:
    std::ofstream file;
};

void exampleFileHandlingWithRAII(const std::string &filename, const std::string &data)
{
    try
    {
        // 使用FileHandler对象管理文件生命周期
        FileHandler fileHandler(filename);

        // 模拟写入数据到文件
        fileHandler.writeToFile(data);

        // 在这里发生异常
        throw std::runtime_error("An exception occurred");
    }
    catch (const std::exception &e)
    {
        // 在异常处理中，FileHandler 对象会被销毁，析构函数会关闭文件
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    exampleFileHandlingWithRAII("example.txt", "Hello, RAII!");

    return 0;
}
