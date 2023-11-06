#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum Operators
{
    P = '+', S = '-',
    M = '*', D = '/',
    LP = '(', RP = ')'
};

int GetPriority(const char op)
{
    if (op == M || op == D)
        return 2;
    else if (op == P || op == S)
        return 1;
    else
        return 0;
}

bool IsOperator(const char token)
{
    return (token == P) || (token == S)
        || (token == M) || (token == D)
        || (token == LP) || (token == RP);
}

bool IsLeftHigher(const char lhs, const char rhs)
{
    return GetPriority(lhs) >= GetPriority(rhs);
}

bool HasHighPriority(stack<char>& opStk, const char token)
{
    return !opStk.empty() && IsLeftHigher(opStk.top(), token);
}

string MakeExpression(stack<char>& opStk, stack<string>& exprStk)
{
    char op = opStk.top(); opStk.pop();
    string a = exprStk.top(); exprStk.pop();
    string b = exprStk.top(); exprStk.pop();
    return b + a + op;
}

string InfixToPostfix(const string& infix)
{
    stack<char> opStk;
    stack<string> exprStk;

    for (auto& token : infix)
    {
        if (IsOperator(token))
        {
            if (token == RP)
            {
                while (opStk.top() != LP)
                {
                    string expr = MakeExpression(opStk, exprStk);
                    exprStk.push(expr);
                }
                opStk.pop();
                continue;
            }
            
            if (token != LP)
            {
                while (HasHighPriority(opStk, token))
                {
                    string expr = MakeExpression(opStk, exprStk);
                    exprStk.push(expr);
                }
            }
            opStk.push(token);
        }
        else
        {
            if (token == ' ') continue;

            exprStk.push({ token });
        }
    }

    while (exprStk.size() > 1)
    {
        string expr = MakeExpression(opStk, exprStk);
        exprStk.push(expr);
    }

    return exprStk.top();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string infix;
    cin >> infix;

    cout << InfixToPostfix(infix);

    return 0;
}