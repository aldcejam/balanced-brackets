#include <iostream>
#include <fstream>
#include <string>
#include "stack/stack.h"

bool isBalanced(const std::string &expression)
{
    Stack<char> s(expression.length());

    for (char ch : expression)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s.isEmpty())
            {
                return false;
            }

            char top = s.peek();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return s.isEmpty();
}

int main()
{
    std::ifstream infile("test_cases.txt");
    std::string expression;

    if (!infile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    while (std::getline(infile, expression))
    {
        if (isBalanced(expression))
        {
            std::cout << "Expression \"" << expression << "\" is balanced." << std::endl;
        }
        else
        {
            std::cout << "Expression \"" << expression << "\" is not balanced." << std::endl;
        }
    }

    infile.close();
    return 0;
}
