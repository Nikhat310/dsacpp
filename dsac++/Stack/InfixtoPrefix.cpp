#include <iostream>
#include <string>
using namespace std;

class myStack
{
    int max;
    char L[100];
    int top;

public:
    myStack()
    {
        max = 100;
        top = -1;
    }

    void Push(char ele)
    {
        if (top == max - 1)
        {
            cout << "Overflow!" << endl;
            return;
        }

        top++;
        L[top] = ele;
    }

    char Pop()
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
};

bool operand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9'))
        return true;
    else
        return false;
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

string rev(string s)
{
    string r = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            r = ')' + r;
        else if (s[i] == ')')
            r = '(' + r;
        else
            r = s[i] + r;
    }

    return r;
}

string intopre(string s, myStack &st)
{
    s = rev(s);

    string p = "";
    s = s + ')';

    st.Push('(');

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (operand(ch))
        {
            p = p + ch;
        }
        else if (ch == '(')
        {
            st.Push(ch); 
        }
        else if (oper(ch))
        {
            char x = st.Pop();

            while (oper(x) &&
                   precedence(x) > precedence(ch))
            {
                p = p + x;
                x = st.Pop();
            }

            st.Push(x);
            st.Push(ch);
        }
        else if (ch == ')')
        {
            char x = st.Pop();

            while (x != '(')
            {
                p = p + x;
                x = st.Pop();
            }
        }
    }

    p = rev(p);
    return p;
}

int main()
{
    string infix;

    cout << "Enter an infix expression : ";
    cin >> infix;

    myStack s;

    string prefix = intopre(infix, s);

    cout << "Prefix expression = " << prefix << endl;

    return 0;
}