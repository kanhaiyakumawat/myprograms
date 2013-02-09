#include "Stack.h"
#include <iostream>

using namespace std;
bool parenthesis_match(char *str)
{
    int i = 0;
    Stack<char> stack;
    while(str[i])
    {
        if(str[i] == '(')
        {
            stack.push('(');
        }
        else if(str[i] == ')')
        {
            stack.pop();
        }
        i++;
    }
    if(stack.is_empty())
    {
        cout<<"matching parenthesis\n";
    }
    else
    {
        cout<<"un-matching parenthesis\n";
    }
}
int main()
{
    char *str ="(())";
    parenthesis_match(str);
    return 0;
}
