
#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

class MyString
{
private:
    int buf_len;
    shared_ptr<char> characters;
    bool create(int buf_len, const char *data)
    {
        this->buf_len = buf_len;

        if (this->buf_len != 0)
        {
            this->characters = shared_ptr<char>(new char[this->buf_len]{});
            if (data)
                strncpy(this->characters.get(), data, this->buf_len);
        }

        return true;
    }

public:
    MyString(int buf_len = 64, const char *data = NULL)
    {
        std::cout << "Constructor(int, char*)" << std::endl;
        this->buf_len = 0;
        this->characters = NULL;
        create(buf_len, data);
    }
    ~MyString()
    {
        cout << "use_count() = " << characters.use_count() << std::endl;
        cout << "calling ~MyString()" << endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const MyString &ms)
    {
        os << "buf_len = " << ms.buf_len;
        os << ", characters = " << static_cast<void *>(ms.characters.get());
        os << " [" << ms.characters << "]";
        return os;
    }
};

int main()
{
    MyString str1(10, "Guangzhou");
    cout << "str1: " << str1 << endl;

    MyString str2 = str1;
    cout << "str2: " << str2 << endl;

    MyString str3;
    cout << "str3: " << str3 << endl;
    str3 = str1;
    cout << "str3: " << str3 << endl;

    return 0;
}