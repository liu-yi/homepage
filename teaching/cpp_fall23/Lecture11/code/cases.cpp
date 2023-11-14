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
        return os << "Parent: " << p.id << ", " << p.name;
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
    Child() : age(0) // 派生类将调用基类的默认构造函数来初始化数据成员。
    {
        cout << "calling Child default constructor Child()" << endl;
    }
    Child(int age) : age(age) // 派生类将调用基类的默认构造函数来初始化数据成员。
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

    Child(const Parent &p, int age) : Parent(p), age(age) // 调用 Parent 拷贝构造函数
    {
        cout << "calling Child constructor Child(Parent, int)" << endl;
    }
    friend ostream &operator<<(ostream &os, const Child &c)
    {
        return os << (Parent &)c << ", Child: " << c.age;
    }
    int get_age()
    {
        return age;
    }
};

void say_hello(Parent &p)
{
    cout << "calling say_hello(Parent &)" << endl;
    p.hello();
}

int main()
{
    Parent p(101, "Liuyi");

    cout << "---------------" << endl;

    cout << "Child c1(19);" << endl;
    Child c1(19);
    cout << "values in c1:\n"
         << c1 << endl;

    cout << "---------------" << endl;

    cout << "Child c2(p, 20);" << endl;
    Child c2(p, 20);
    cout << "values in c2:\n"
         << c2 << endl;

    cout << "---------------" << endl;

    cout << "Child c3 = c2;" << endl;
    Child c3 = c2; // 在不初始化基类组件的情况下调用子复制构造函数
    cout << "values in c3:\n"
         << c3 << endl;

    cout << "---------------" << endl;

    cout << "Child c4; c4 = c2" << endl;
    Child c4;
    cout << "Before assignment, values in c4:\n"
         << c4 << endl;
    c4 = c2; // 调用 Child 赋值运算符
    cout << "values in c4:\n"
         << c4 << endl;

    cout << "---------------" << endl;

    Parent c5 = Child();
    c5.hello();
    c5.Parent::hello();
    // cout << c5.get_age() << endl;
    // c5.Child::get_age() << endl;

    cout << "---------------" << endl;

    Parent *pc6 = new Child();
    pc6->hello();
    pc6->Parent::hello();
    // cout << pc6->get_age() << endl;
    // pc6->Child::get_age() << endl;
    delete pc6;

    cout << "---------------" << endl;

    say_hello(c4);
    say_hello(c5);
}