
#include<iostream>
using namespace std;

// ── Stack class ──────────────────────────────────────
class Stack {
    static const int MAX = 100;
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(int ele) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ele;
    }
int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// ── FactorialStack class ─────────────────────────────
class FactorialStack {
public:
    long long factorial(int n) {
        Stack s;

        // Push n, n-1, n-2, ... 1 onto the stack
        for (int i = n; i >= 1; i--)
            s.push(i);

        long long result = 1;

        // Pop each value and multiply
        while (!s.isEmpty())
            result *= s.pop();

        return result;
    }
};

// ── main ─────────────────────────────────────────────
int main() {
    FactorialStack ob;
    int num;

    cout << "Enter a number: ";
    cin  >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers.\n";
    else if (num == 0)
        cout << "Factorial of 0 is 1\n";
    else
        cout << "Factorial of " << num << " is " << ob.factorial(num) << "\n";

    return 0;
}