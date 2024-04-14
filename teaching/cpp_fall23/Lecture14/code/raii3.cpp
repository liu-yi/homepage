#include <iostream>
#include <memory>

class CustomResource
{
public:
    CustomResource(const std::string &name) : name(name)
    {
        std::cout << "Custom resource " << name << " allocated" << std::endl;
    }

    ~CustomResource()
    {
        std::cout << "Custom resource " << name << " deallocated" << std::endl;
    }

private:
    std::string name;
};

void RAII(const std::string &name)
{
    try
    {
        // 使用std::unique_ptr直接管理自定义资源生命周期
        std::unique_ptr<CustomResource> resource(new CustomResource(name));

        // 其他操作...

        // 在这里发生异常
        throw std::runtime_error("An exception occurred");
    }
    catch (const std::exception &e)
    {
        // 在异常处理中，std::unique_ptr 会自动释放自定义资源
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::string name = "example";
    RAII(name);

    return 0;
}
