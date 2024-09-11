
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 未定义的行为，不提倡使用
    const int j = 3; // 声明 j 为 const
    int *pj = const_cast<int *>(&j);
    *pj = 4; // 未定义行为
    std::cout << "j = " << j << " ,addr(j):" << &j << '\n';
    std::cout << "*pj = " << *pj << " ,addr(*pj):" << pj << '\n';

    // 正常的行为
    int j1 = 3; // 最初声明为非const
    const int *cpj1 = &j1;
    int *pj1 = const_cast<int *>(cpj1); // cpj1最终指向的值（即j1的值）为非const类型，可以使用const_cast
    *pj1 = 4;
    std::cout << "j1 = " << j1 << " ,addr(j1):" << &j1 << '\n';
    std::cout << "*pj1 = " << *pj1 << " ,addr(*pj1):" << pj1 << '\n';
}
