#include <iostream>
using namespace std;
int move(int n, char A, char B, char C)
{
    // n代表现在需要将第n个圆盘放到目标位置C
    if (n == 1)
    { // 当递归到第1个圆盘时，直接将其放到目标位置C
        cout << A << "->" << C << endl;
        return 1;
    }
    else
    {
        int step = move(n - 1, A, C, B);
        // 1.将n-1层圆盘放到辅助位置B。把B当作目标位置，C当作辅助位置，所以BC互换
        cout << A << "->" << C << endl;
        step++;
        // 将第n个圆盘放到目标位置C上
        step += move(n - 1, B, A, C);
        return step;
        // 将n-1层圆盘放到目标位置C。A当作辅助位置，B当作开始位置，所以AB互换
    }
}
int main()
{
    int step = move(4, 'A', 'B', 'C');
    // 开始时，A是开始位置，B是辅助位置，C是目标位置
    cout << "step: " << step << endl;
    return 0;
}
