#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {

public:
    // Get height
    int getHeight(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    // Get balance factor
    int getBalance(Node* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right Rotation (LL Case)
    Node* rightRotate(Node* z) {
        Node* y = z->left;
        Node* T3 = y->right;

        y->right = z;
        z->left = T3;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Left Rotation (RR Case)
    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* T2 = y->left;

        y->left = z;
        z->right = T2;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Insert with AVL balancing
    Node* insert(Node* root, int key) {

        // BST insert
        if (root == NULL)
            return new Node(key);

        if (key < root->data)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);

        // Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Balance factor
        int balance = getBalance(root);

        // LL Case
        if (balance > 1 && key < root->left->data)
            return rightRotate(root);

        // RR Case
        if (balance < -1 && key > root->right->data)
            return leftRotate(root);

        // LR Case
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL Case
        if (balance < -1 && key < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Inorder Traversal
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {

    AVLTree avl;
    Node* root = NULL;
    int value;

    cout << "Enter numbers for AVL Tree (enter -1 to stop):\n";

    while (true) {
        cout << "Enter data: ";
        cin >> value;

        if (value == -1)
            break;

        root = avl.insert(root, value);
    }

    cout << "\nInorder Traversal of AVL Tree:\n";
    avl.inorder(root);
    cout << endl;

    return 0;
}