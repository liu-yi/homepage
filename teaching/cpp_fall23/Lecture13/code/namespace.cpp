#include <string>
#include <iostream>
using namespace std;
using std::cout;
using std::string;

// 两个在不同命名空间中定义的名字相同的变量
namespace myown1
{
    string user_name = "myown1";
}

namespace myown2
{
    string user_name = "myown2";
}

// int main()
// {
//     cout << "\n"
//          << "Hello, "
//          << myown1::user_name
//          << "... and goodbye!\n";

//     cout << "\n"
//          << "Hello, "
//          << myown2::user_name
//          << "... and goodbye!\n";
//     return 0;
// }
int main()
{
    using namespace myown1;
    cout << "\n"
         << "Hello, "
         << user_name << "... and goodbye!\n";

    cout << "\n"
         << "Hello, "
         << myown2::user_name
         << "... and goodbye!\n";

    // user_name = "here";
    // cout << "\n"
    //      << "Hello, "
    //      << user_name << "... and goodbye!\n";
}