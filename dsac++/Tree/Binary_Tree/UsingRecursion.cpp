#include<iostream>
using namespace std;

// ── Node ─────────────────────────────────────────────
struct Node {
    int   data;
    Node* left;
    Node* right;
    Node(int val) {
        data  = val;
        left  = right = nullptr;
    }
};

// ── Queue (holds Node pointers) ──────────────────────
class Queue {
    static const int MAX = 10;
    Node* arr[MAX];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }

    bool isEmpty() { return front > rear; }

    void enqueue(Node* node) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = node;
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

    void create() {
        Queue q;
        int data;

        cout << "=== Binary Tree Builder ===\n";
        cout << "(Enter -1 for no child)\n\n";

        cout << "Enter root: ";
        cin  >> data;
        if (data == -1) { cout << "Empty tree.\n"; return; }

        root = new Node(data);
        q.enqueue(root);

        while (!q.isEmpty()) {
            Node* curr = q.dequeue();

            cout << "Left  child of [" << curr->data << "]: ";
            cin  >> data;
            if (data != -1) {
                curr->left = new Node(data);
                q.enqueue(curr->left);
            }

            cout << "Right child of [" << curr->data << "]: ";
            cin  >> data;
            if (data != -1) {
                curr->right = new Node(data);
                q.enqueue(curr->right);
            }
        }
        cout << "\nTree created successfully!\n";
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

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
    tree.create();

    cout << "\nInorder   : ";
    tree.inorder(tree.root);

    cout << "\nPreorder  : ";
    tree.preorder(tree.root);

    cout << "\nPostorder : ";
    tree.postorder(tree.root);
    cout << "\n";

    return 0;
}
