// Binary Tree Creation without Recursion — user-defined Queue
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

// ── User-defined Queue (stores Node*) ────────────────
class Queue {
    static const int SIZE = 50;
    Node* arr[SIZE];
    int   front, rear;
public:
    Queue() { front = 0; rear = -1; }

    bool isEmpty() { return front > rear; }

    void enqueue(Node* x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    Node* dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return nullptr;
        }
        return arr[front++];
    }
};

// ── BinaryTree ───────────────────────────────────────
class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }

    // ── Creation using user-defined Queue ────────────
    Node* create() {
        Queue q;
        int data;

        cout << "Enter root value (-1 for no node): ";
        cin  >> data;
        if (data == -1) return nullptr;

        root = new Node(data);
        q.enqueue(root);

        while (!q.isEmpty()) {
            Node* current = q.dequeue();

            // ── left child ──────────────────────────────
            cout << "Enter left  child of " << current->data << " (-1 for no node): ";
            cin  >> data;
            if (data != -1) {
                current->left = new Node(data);
                q.enqueue(current->left);
            }

            // ── right child ─────────────────────────────
            cout << "Enter right child of " << current->data << " (-1 for no node): ";
            cin  >> data;
            if (data != -1) {
                current->right = new Node(data);
                q.enqueue(current->right);
            }
        }
        return root;
    }

    // ── Inorder : Left → Root → Right ────────────────
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // ── Preorder : Root → Left → Right ───────────────
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // ── Postorder : Left → Right → Root ──────────────
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
};

// ── main ─────────────────────────────────────────────
int main() {
    BinaryTree tree;
    tree.root = tree.create();

    cout << "\nInorder   : ";
    tree.inorder(tree.root);

    cout << "\nPreorder  : ";
    tree.preorder(tree.root);

    cout << "\nPostorder : ";
    tree.postorder(tree.root);
    cout << "\n";

    return 0;
}
