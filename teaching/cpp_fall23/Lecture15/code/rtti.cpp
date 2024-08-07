#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
public:
    Person(string name=""):name(name){};
    virtual ~Person(){}
    string getInfo(){return name;}
};

class Student: public Person
{
    string studentid;
public:
    Student(string name="", string sid=""):Person(name),studentid(sid){};
    string getInfo(){return name+":("+studentid + ")";}
};

int main()
{
    Person person("Yi");
    Student student("Sam", "2023");
    Person* pp = &student;
    Person& rp = student;
    Student * ps = (Student*)&person; // danger!
    cout << "person.getInfo():" << person.getInfo() << endl;
    cout << "pp->getInfo():" << pp->getInfo() << endl;
    cout << "rp.getInfo():" <<rp.getInfo() << endl;
    cout << "ps->getInfo():" << ps->getInfo() << endl; // danger if getInfo is not virtual

    ps = dynamic_cast<Student*>(&person);// add virtual? delete virtual?
    printf("address = %p\n", ps);
    pp = dynamic_cast<Person*>(&student);
    printf("address = %p\n", pp);
    return 0;
}