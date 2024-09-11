#include <iostream>
#include <string>
using namespace std;

class Person
{
  public:
    string name;
    Person(string n): name(n){}
    virtual void print()
    {
        cout << "Name: " << name << endl;
    }
};

// class Person2
// {
//   public:
//     string name;
//     Person2(string n): name(n){}
//     virtual void print() = 0; 
// };

class Student: public Person
{
  public:
    string id;
    Student(string n, string i): Person(n), id(i){}
    void print() 
    {
        cout << "Name: " << name;
        cout << ". ID: " << id << endl;
    }
};

// class Student2: public Person2
// {
//   public:
//     string id;
//     Student2(string n, string i): Person2(n), id(i){}
//     void print() 
//     {
//         cout << "Name: " << name;
//         cout << ". ID: " << id << endl;
//     }
// };

void printObjectInfo(Person & p)
{
    p.print();
}

int main()
{
    {
        Student stu("yi", "2019");
        printObjectInfo(stu);  
        Person &stu_ref = stu;
        printObjectInfo(stu_ref); 
    }

    {
        Person * p = new Student("liu", "2020");
        p->print(); 
        delete p; 
    }

    { //if you want to call a function in the base class
        Student stu("li", "2021");
        stu.Person::print();

        Person * p = new Student("liu", "2020");
        p->Person::print(); 
        delete p; 
    }

    // {
    //     // Person2 person2("liu");
    //     Student2 stu2("liu", "2020");
    //     Person2 *p2 = &stu2;
    //     Person2 &stu2_ref = stu2;
    //     stu2.print();
    //     p2->print();
    //     stu2_ref.print();

    // }

    return 0;
}