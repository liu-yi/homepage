#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    Person(string n) : name(n) {}
    void print()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person
{
public:
    string id;
    Student(string n, string i) : Person(n), id(i) {}
    void print()
    {
        cout << "Name: " << name;
        cout << ". ID: " << id << endl;
    }
};

void printObjectInfo(Person &p)
{
    p.print();
}

int main()
{
    {
        Student stu("yi", "2019");
        stu.print();

        printObjectInfo(stu);

        Person &stu_ref = stu;
        printObjectInfo(stu_ref);
    }

    {
        Person *p = new Student("liu", "2020");
        p->print();
        delete p;
    }

    { 
        Student stu("li", "2021");
        stu.Person::print();

        Person *p = new Student("liu", "2020");
        p->Person::print();
        // p->Student::print();//可以吗？
        delete p;
    }

    return 0;
}