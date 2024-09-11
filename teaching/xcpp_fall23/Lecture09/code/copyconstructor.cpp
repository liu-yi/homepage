#include <iostream>
#include <string>

class MyTime
{
    int hours;
    int minutes;

public:
    MyTime() : hours(0), minutes(0)
    {
        std::cout << "Constructor MyTime()" << std::endl;
    }
    MyTime(int m) : hours(0), minutes(m)
    {
        std::cout << "Constructor MyTime(int)" << std::endl;
        this->hours += this->minutes / 60;
        this->minutes %= 60;
    }
    MyTime(int h, int m) : hours(h), minutes(m)
    {
        std::cout << "Constructor MyTime(int,int)" << std::endl;
    }

    MyTime(const MyTime &t)
    {
        this->hours = t.hours + 1;
        this->minutes = t.minutes + 1;
        std::cout << "Copy Constructor MyTime(MyTime &t)" << std::endl;
    }

    ~MyTime()
    {
        std::cout << "Deconstructor ~MyTime" << std::endl;
    }

    int get_hours()
    {
        return hours;
    }

    friend std::ostream &operator<<(std::ostream &os, const MyTime &t)
    {
        os << t.hours << " hours and " << t.minutes << " minutes.";
        return os;
    }
};

void test_function(MyTime mt)
{
    std::cout << "call test_function(MyTime)" << std::endl;
    std::cout << mt << std::endl;
}

MyTime get_copy()
{
    std::cout << "call get_copy()" << std::endl;
    MyTime mt(30, 1);
    return mt;
    // return 1;
}

MyTime get_copy_by_index(int index)
{
    std::cout << "call get_copy_by_index()" << std::endl;
    MyTime mts[2]{{30, 1}, {30, 1}};
    return mts[index];
}

int main()
{
    MyTime t1(1, 58);
    MyTime t2(t1); // copy constructor
    std::cout << "t2: " << t2 << std::endl;
    MyTime t3 = t1; // copy constructor
    std::cout << "t3: " << t3 << std::endl;

    std::cout << "==============" << std::endl;

    MyTime mt(2, 0);
    test_function(mt);

    std::cout << "==============" << std::endl;

    // MyTime mt = get_copy();
    // std::cout << "mt " << mt << std::endl;

    // MyTime mt_1 = get_copy_by_index(1);
    // std::cout << "mt_1 " << mt_1 << std::endl;
}
