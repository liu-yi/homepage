// 设计一个通用的栈类模板 CustomStack，该模板要求支持不同数据类型的栈操作，包括推入元素（push）、弹出元素（pop）、获取栈顶元素（top）、检查栈是否为空（isEmpty）。
// 要求：
// 实现通用的栈类模板 CustomStack，支持模板参数化，栈用数组实现（栈容量为5，用模板的非类型参数设定）。
// 在通用模板中处理栈为空时的情况，输出 "Stack is empty. Cannot pop."
// 特例化处理整数类型（int）的栈，在该特例化处理栈为空时输出 "Special Handling: Stack is empty. Cannot pop."
// 在主函数中进行测试，包括使用双精度浮点数和整数类型的栈，演示栈的基本操作。
#include <iostream>
using namespace std;

template <typename T, int num>
class CustomStack
{
public:
    int top;
    T stack[num];
    CustomStack()
    {
        this->top = -1;
    }
    bool push(T elem)
    {
        if (this->top < num)
        {
            this->stack[++top] = elem;
            return true;
        }
        else
        {
            cout << "栈已满，无法入栈" << endl;
            return false;
        }
    }
    T &Pop()
    {
        if (!isEmpty())
        {
            T elem = stack[top--];
            return elem;
        }
    }
    T &Top()
    {
        if (!isEmpty())
            return stack[this->top];
    }
    bool isEmpty()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return true;
        }
        return false;
    }
};

template <int num>
class CustomStack<int, num>
{
    int top;
    int stack[num];

public:
    void print(){
        cout << num << endl;
    }

};
int main()
{
    CustomStack<int, 5> s1;
    s1.print();
}
