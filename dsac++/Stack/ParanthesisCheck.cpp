#include<iostream>
#include<string>
using namespace std;

// ── Stack class (char) ───────────────────────────────
class Stack {
    static const int MAX = 100;
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(char ele) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ele;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

// ── ParenthesesChecker class ─────────────────────────
class ParenthesesChecker {
public:
    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }


bool isBalanced(string exp) {
        Stack s;
        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);          // opening → push
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (s.isEmpty())
                    return false;    // closing with nothing open
                char top = s.pop();
                if (!isMatching(top, ch))
                    return false;    // mismatched pair e.g. ( ]
            }
        }
        return s.isEmpty();         // leftover opens = unbalanced
    }
};


// ── main ─────────────────────────────────────────────
int main() {
    ParenthesesChecker ob;
    string exp;

    cout << "Enter expression with parentheses: ";
    getline(cin, exp);

    if (ob.isBalanced(exp))
        cout << "Parentheses are balanced\n";
    else
        cout << "Parentheses are NOT balanced\n";

    return 0;
}