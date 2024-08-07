#include <iostream>
#include <cstring>

class Student
{
  private:
    char name[4];
    int born;
    bool male; 
  public:
    void setName(const char * s)
    {
        strncpy(name, s, sizeof(name));
    }
    void setBorn(int b)
    {
        born = b;
    }
    void setGender(bool isMale)
    {
        male = isMale;
    }
    void printInfo()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Born in " << born << std::endl;
        std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
    }
};

int main()
{
    Student yi;
    yi.setName("Yi");
    yi.setBorn(2000);
    yi.setGender(true);
    yi.born = 2001; // you cannot access a private member
    yi.printInfo();
    return 0;
}