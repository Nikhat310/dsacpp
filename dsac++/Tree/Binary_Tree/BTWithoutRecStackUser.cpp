// Without Recursion — using user-defined Stack
#include<iostream>
using namespace std;

// ── Node ─────────────────────────────────────────────
struct Node {
    int   data;
    Node* left;
    Node* right;
    Node(int value) {
        data  = value;
        left  = right = nullptr;
    }
};

// ── User-defined Stack (stores Node*) ────────────────
class Stack {
    static const int CAPACITY = 50;
    Node* arr[CAPACITY];
    int   top;
public:
    Stack() { top = -1; }

    void push(Node* x) {
        if (top == CAPACITY - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    Node* pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return nullptr;
        }
        return arr[top--];
    }

    Node* peek() {
        if (top == -1) return nullptr;
        return arr[top];
    }

    bool isEmpty() { return top == -1; }
};

// ── BinaryTree ───────────────────────────────────────
class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }

    // ── Inorder : Left → Root → Right ────────────────
    void inorder(Node* root) {
        Stack stack;
        Node* current = root;

        while (current != nullptr || !stack.isEmpty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            current = stack.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    // ── Preorder : Root → Left → Right ───────────────
    void preorder(Node* root) {
        if (root == nullptr) return;
        Stack stack;
        stack.push(root);

        while (!stack.isEmpty()) {
            Node* current = stack.pop();
            cout << current->data << " ";
            // push right first so left is processed first
            if (current->right != nullptr) stack.push(current->right);
            if (current->left  != nullptr) stack.push(current->left);
        }
    }

    // ── Postorder : Left → Right → Root ──────────────
    void postorder(Node* root) {
        if (root == nullptr) return;
        Stack stack1, stack2;
        stack1.push(root);

        while (!stack1.isEmpty()) {
            Node* current = stack1.pop();
            stack2.push(current);
            if (current->left  != nullptr) stack1.push(current->left);
            if (current->right != nullptr) stack1.push(current->right);
        }
        while (!stack2.isEmpty())
            cout << stack2.pop()->data << " ";
    }
};

// ── main ─────────────────────────────────────────────
int main() {
    BinaryTree tree;

    tree.root              = new Node(1);
    tree.root->left        = new Node(2);
    tree.root->right       = new Node(3);
    tree.root->left->left  = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Tree created successfully!\n";

    cout << "Inorder   : ";
    tree.inorder(tree.root);

    cout << "\nPreorder  : ";
    tree.preorder(tree.root);

    cout << "\nPostorder : ";
    tree.postorder(tree.root);
    cout << "\n";

    return 0;
}
