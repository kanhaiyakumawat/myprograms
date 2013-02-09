#include <iostream>
#include <stack>

const char OPEN_PARANTHESIS = '(';
const char CLOSE_PARANTHESIS = ')';

using namespace std;

int preference(char c)
{
        switch(c)
        {
                case '+':
                case '-':
                        {
                                return 0;
                        }
                case '*':
                case '/':
                        {
                                return 1;
                        }
                case '^':
                        {
                                return 2;
                        }
                default: throw;
        }
}

char* infix2postfix(char exp[])
{
        std::stack<char> S;
        char *output = new char[100];
        char c = exp[0];
        int i = 0;
        int j = 0;
        while(c != '\n')
        {
                if(c >= '0' && c <= '9')
                {
                        output[i] = c;
                        i++;
                }
                else
                {
                        if(c == CLOSE_PARANTHESIS)
                        {
                                char c = S.top();
                                S.pop();
                                while(c != OPEN_PARANTHESIS)
                                {
                                        output[i] = c;
                                        c = S.top();
                                        S.pop();
                                        i++;
                                }
                        }
                        else if(c == OPEN_PARANTHESIS || S.empty() || S.top() == OPEN_PARANTHESIS || c == S.top() || preference(S.top()) < preference(c))
                        {
                                S.push(c);
                        }
                        else if(preference(S.top()) >= preference(c))
                        {
                                char cc = S.top();
                                S.pop();
                                output[i++] = cc;
                                S.push(c);
                        }
                }
                c = exp[++j];
        }
        while(!S.empty())
        {
                output[i] = S.top();
                S.pop();
                i++;
        }
        output[i] = '\n';
        return output;
}
int main()
{
        char *exp = "1*(2+3+4)\n";
        cout<<"infix: "<<exp<<endl<<"postfix: "<<infix2postfix(exp)<<endl;
        return 0;
}
