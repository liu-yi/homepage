#include <iostream>
using namespace std;
class Student
{
private:
    string m_name;
    int m_age;
    float m_score;

public:
    void setage(int m_age);
    Student(string name, int age, float score);
    void show();
};
Student::Student(string name, int age, float score)
{
    m_name = name;
    m_age = age;
    m_score = score;
}
void Student::setage(int m_age)
{
    m_age = m_age;
}
void Student::show()
{
    cout << m_name << " age: " << m_age << ", score:" << m_score << endl;
}
int main()
{
    Student stu("Yi", 5, 92.5f);
    stu.setage(10);
    stu.show();

    Student *pstu = new Student("Liu", 15, 96);
    pstu->setage(20);
    pstu->show();
    return 0;
}
