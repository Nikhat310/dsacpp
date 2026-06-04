#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top < 0) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack (bottom -> top): ";
    for (int i = 0; i <= top; i++)
        cout << stack[i] << " ";
    cout << endl;
}

void reverseStack() {
    int temp[MAX];
    int tempTop = -1;

    // Pop all elements into temp (stored in reverse order)
    while (top >= 0) {
        temp[++tempTop] = pop();
    }

    // Push back from temp bottom to top (NOT popping, just indexing)
    for (int i = 0; i <= tempTop; i++) {
        push(temp[i]);
    }
}

int main() {
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        push(val);
    }

    cout << "\nBefore Reverse:" << endl;
    display();

    reverseStack();

    cout << "\nAfter Reverse:" << endl;
    display();

    return 0;
}