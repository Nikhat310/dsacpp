#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class Queue {
    int front, rear, size;
    Node** arr;
public:
    Queue(int capacity) {
        size = capacity;
        arr = new Node*[size];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(Node* x) {
        if (rear == size - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }

    Node* dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return nullptr;
        }
        return arr[front++];
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    Node* create() {
        Queue q(10);
        int data;

        cout << "Enter root value: ";
        cin >> data;

        if (data == -1) return nullptr;

        root = new Node(data);
        q.enqueue(root);

        while (!q.isEmpty()) {
            Node* current = q.dequeue();

            // Left child
            cout << "Enter left child of " << current->data << " (-1 for no node): ";
            int leftData;
            cin >> leftData;

            if (leftData!= -1) {
                current->left = new Node(leftData);
                q.enqueue(current->left);
            }

            // Right child
            cout << "Enter right child of " << current->data << " (-1 for no node): ";
            int rightData;
            cin >> rightData;

            if (rightData!= -1) {
                current->right = new Node(rightData);
                q.enqueue(current->right);
            }
        }
        return root;
    }

    void inorder(Node* root) {
        if (root!= nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root!= nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root!= nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.create();

    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}