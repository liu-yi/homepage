#include <iostream>
#include <memory>

using namespace std;

class ResourceException : public std::runtime_error
{
public:
    ResourceException(const std::string &message) : std::runtime_error(message) {}
};

class Resource
{
public:
    Resource()
    {
        std::cout << "Resource() is called" << endl;
    }
    ~Resource()
    {
        std::cout << "~Resource() is called" << endl;
    }
    void throwException()
    {
        throw ResourceException("Resource exception");
    }
};

int main()
{
    try
    {
        Resource *r = new Resource;
        r->throwException();
        delete r;
    }
    catch (const ResourceException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// try
// {
//     unique_ptr<Resource> r = unique_ptr<Resource>(new Resource);
//     r->throwException();
// }
// catch (const ResourceException &e)
// {
//     std::cerr << "Error: " << e.what() << std::endl;
// }