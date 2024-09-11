#include <string>
#include <iostream>
using namespace std;

class Parent
{
private:
    int id;
    string name;

public:
    Parent() : id(1), name("null")
    {
        cout << "calling default constructor Parent()" << endl;
    }

    Parent(int i, string n) : id(i), name(n)
    {
        cout << "calling Parent constructor Parent(int, string)" << endl;
    }

    Parent(const Parent &p)
    {
        cout << "calling Parent copy constructor Parent(const Parent &p)" << endl;
        id = p.id;
        name = p.name;
    }

    friend ostream &operator<<(ostream &os, const Parent &p)
    {
        return os << "Parent: " << p.id << ", " << p.name << endl;
    }

    void hello()
    {
        cout << "Parent: hello" << endl;
    }
};

class Child : public Parent
{
private:
    int age;

public:
    Child() : age(0) // The derived class will call the default constructor of the base class to initialize the data members.
    {
        cout << "calling Child default constructor Child()" << endl;
    }
    Child(int age) : age(age) // The derived class will call the default constructor of the base class to initialize the data members.
    {
        cout << "calling Child constructor Child(int)" << endl;
    }

    Child(const Child &c) : age(c.age)
    {
        cout << "calling Child copy constructor Child(const Child&) without init Parent" << endl;
    }

    // Child(const Child &c) : Parent(c), age(c.age)
    // {
    //     cout << "calling Child copy constructor Child(const Child&)" << endl;
    // }
    Child(const Parent &p, int age) : Parent(p), age(age) // Call Parent copy constructor
    {
        cout << "calling Child constructor Child(Parent, int)" << endl;
    }
    friend ostream &operator<<(ostream &os, const Child &c)
    {
        return os << (Parent &)c << "Child: " << c.age << endl;
    }
    int get_age()
    {
        return age;
    }
};

void say_hello(Parent &parrent)
{
    cout << "calling say_hello(Parent &)" << endl;
    parrent.hello();
}

int main()
{
    Parent p(101, "Liuyi");

    cout << "---------------" << endl;

    cout << "Child c1(19);" << endl;
    Child c1(19);
    cout << "values in c1:\n"
         << c1 << endl;

    cout << "Child c2(p, 20);" << endl;
    Child c2(p, 20);
    cout << "values in c2:\n"
         << c2 << endl;

    cout << "Child c3 = c2;" << endl;
    Child c3 = c2; // Call Child copy constructor without initializing the base class component
    cout << "values in c3:\n"
         << c3 << endl;

    cout << "Child c4; c4 = c2" << endl;
    Child c4;
    cout << "Before assignment, values in c4:\n"
         << c4 << endl;
    c4 = c2; // Call Child assignment operator
    cout << "values in c4:\n"
         << c4 << endl;

    cout << "---------------" << endl;

    Parent c5 = Child();
    c5.hello();
    c5.Parent::hello();
    // cout << c5.get_age() << endl;
    // c5.Child::get_age() << endl;

    cout << endl;

    Parent *pc6 = new Child();
    pc6->hello();
    pc6->Parent::hello();
    // cout << pc6->get_age() << endl;
    // pc6->Child::get_age() << endl;
    delete pc6;

    cout << endl;

    say_hello(c5);
    say_hello(c4);
}