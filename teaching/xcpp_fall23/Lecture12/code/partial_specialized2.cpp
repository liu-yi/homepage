#include <iostream>
using namespace std;

template <typename T>
class Bag
{
    T *elem;
    int size;
    int max_size;

public:
    Bag() : elem(0), size(0), max_size(1)
    {

        cout << "Original class templete Bag<T>" << endl;
    }
    void add(T t)
    {
        T *tmp;
        if (size + 1 >= max_size)
        {
            max_size *= 2;
            tmp = new T[max_size];
            for (int i = 0; i < size; i++)
            {
                tmp[i] = elem[i];
            }
            tmp[size++] = t;
            delete[] elem;
            elem = tmp;
        }
        else
        {
            elem[size++] = t;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << elem[i] << " ";
        }
        cout << endl;
    }
};

template <typename T>
class Bag<T *> // 为指针类型的部分特例化
{
    T *elem;
    int size;
    int max_size;

public:
    Bag() : elem(0), size(0), max_size(1)
    {

        cout << "Partial specialization class templete Bag<T*>" << endl;
    }
    void add(T *t)
    {
        T *tmp;
        if (t == nullptr)
        {
            cout << "Null pointer" << endl;
            return;
        }
        if (size + 1 >= max_size)
        {
            max_size *= 2;
            tmp = new T[max_size];
            for (int i = 0; i < size; i++)
            {
                tmp[i] = elem[i];
            }
            tmp[size++] = *t; // 如果没有部分特例化，则只添加指针本身。
            delete[] elem;
            elem = tmp;
        }
        else
        {
            elem[size++] = *t; // 如果没有部分特例化，则只添加指针本身。
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << elem[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Bag<int> bag1;
    bag1.add(1);
    bag1.add(2);
    bag1.print();

    Bag<int *> bag2;
    int a = 1;
    int b = 2;
    bag2.add(&a);
    bag2.add(&b);
    a = 3;
    bag2.print();
}