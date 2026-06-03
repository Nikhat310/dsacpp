#include<iostream>
#include<string>
#include<cmath>  // added for pow() function
using namespace std;

class MyStack
{
    int arr[20];
    int top;
public:
    MyStack()
    {
        top = -1;
    }
    void push(int ele)
    {
        top++;
        arr[top] = ele;
    }
    int pop()
    {
        int item = arr[top];
        arr[top] = 0;
        top = top - 1;
        return item;
    }
};

class Pre_Evaluate {
    MyStack st;
public:
    bool isOperand(char ch)
    {
        return ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'));
    }
    bool isOperator(char ch)
    {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');  // ^ added
    }

    int preEval(string prefix)
    {
        int item1, item2, r = 0;

        for (int i = prefix.length() - 1; i >= 0; i--)
        {
            char ch = prefix[i];

            if (ch == ' ')
            {
                continue;
            }

            if (isOperand(ch))
            {
                if (ch >= '0' && ch <= '9')
                {
                    int su = 0;
                    int place = 1;
                    while (i >= 0 && isOperand(prefix[i]) && prefix[i] >= '0' && prefix[i] <= '9')
                    {
                        su = su + (prefix[i] - '0') * place;
                        place *= 10;
                        i--;
                    }
                    i++;
                    st.push(su);
                }
                else
                {
                    cout << "Enter the value : " << ch << " : ";
                    cin >> r;
                    st.push(r);
                }
            }

            if (isOperator(ch))
            {
                item1 = st.pop();
                item2 = st.pop();

                if (ch == '+')
                    st.push(item1 + item2);
                else if (ch == '-')
                    st.push(item1 - item2);
                else if (ch == '*')
                    st.push(item1 * item2);
                else if (ch == '/')
                    st.push(item1 / item2);
                else if (ch == '^')                          // ^ case added
                    st.push((int)pow(item1, item2));         // pow() returns double, cast to int
                else
                {
                    cout << "Invalid Operator";
                    exit(0);
                }
            }
        }
        return st.pop();
    }
};

int main()
{
    Pre_Evaluate ob;
    string prefix;
    cout << "Enter the prefix expression : ";
    getline(cin, prefix);
    cout << "Prefix evaluated result = " << ob.preEval(prefix);
    return 0;
}