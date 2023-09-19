#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::string str1 = "Hello";
    std::string str2 = "JNU";
    std::string result = str1 + ", " + str2;

    cout << "result = " + result << endl;

    cout << "The length is " << result.length() << endl;

    cout << "str1 < str2 is " << (str1 < str2) << endl;

    return 0;
}