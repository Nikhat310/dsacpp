#include <iostream>
#include <string>
using namespace std;

class MyStack
{
    int max = 100;
    char L[100];
    int top;

public:
    MyStack()
    {
        top = -1;
    }

    void push(char ele)
    {
        if (top == max - 1)
        {
            cout << "Overflow!" << endl;
            return;
        }

        top++;
        L[top] = ele;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Underflow!" << endl;
            return '\0';
        }

        char ele = L[top];
        top--;
        return ele;
    }

    char peek()
    {
        if (top == -1)
            return '\0';

        return L[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class InfixToPostfix
{
public:
    bool operand(char ch)
    {
        return ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9'));
    }

    bool oper(char ch)
    {
        return (ch == '+' || ch == '-' ||
                ch == '*' || ch == '/' ||
                ch == '^');
    }

    int precedence(char ch)
    {
        if (ch == '^')
            return 3;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '+' || ch == '-')
            return 1;
        else
            return 0;
    }

    string intopost(string s, MyStack &L)
    {
        string p = "";

        s = s + ')';
        L.push('(');

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (operand(ch))
            {
                p = p + ch;
            }
            else if (ch == '(')
            {
                L.push(ch);
            }
            else if (oper(ch))
            {
                char x = L.pop();

                while (oper(x) &&
                       precedence(x) >= precedence(ch))
                {
                    p = p + x;
                    x = L.pop();
                }

                L.push(x);
                L.push(ch);
            }
            else if (ch == ')')
            {
                char x = L.pop();

                while (x != '(')
                {
                    p = p + x;
                    x = L.pop();
                }
            }
        }

        return p;
    }
};

int main()
{
    MyStack s;
    InfixToPostfix ob;

    string infix;

    cout << "Enter an infix expression : ";
    getline(cin, infix);

    string postfix = ob.intopost(infix, s);

    cout << "Postfix expression = "
         << postfix << endl;

    return 0;
}