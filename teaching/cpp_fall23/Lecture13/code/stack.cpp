#include <iostream>
#include <stack>
#include <string>

bool isBracketMatch(const std::string &expression)
{
    std::stack<char> brackets;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (brackets.empty())
            {
                return false; // 括号不匹配
            }

            char top = brackets.top();
            brackets.pop();

            // 检查括号匹配
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{'))
            {
                return false; // 括号不匹配
            }
        }
    }

    return brackets.empty(); // 如果栈为空，则所有括号匹配
}

int main()
{
    std::string expression1 = "((a + b) * (c - d))";
    std::string expression2 = "{[a + b] * (c - d)}";
    std::string expression3 = "{[a + b] * }(c - d)}";

    std::cout << "Expression 1 is " << (isBracketMatch(expression1) ? "balanced" : "not balanced") << std::endl;
    std::cout << "Expression 2 is " << (isBracketMatch(expression2) ? "balanced" : "not balanced") << std::endl;
    std::cout << "Expression 3 is " << (isBracketMatch(expression3) ? "balanced" : "not balanced") << std::endl;

    return 0;
}
