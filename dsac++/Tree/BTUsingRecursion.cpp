// By using Recursion


#include<iostream>
using namespace std;

// ── Node ─────────────────────────────────────────────
struct Node {
    int   data;
    Node* left;
    Node* right;
    Node(int value) {
        data  = value;
        left  = nullptr;
        right = nullptr;
    }
};

// ── BinaryTree ────────────────────────────────────────
class BinaryTree {
public:
    Node* root;

    BinaryTree() 
    { 
        root = nullptr;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};

// ── main ──────────────────────────────────────────────
int main() {
    BinaryTree tree;

    // create root
    tree.root = new Node(1);

    // create children
    tree.root->left        = new Node(2);
    tree.root->right       = new Node(3);
    tree.root->left->left  = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Tree created successfully!\n";

    cout << "Inorder Traversal:  ";
    tree.inorder(tree.root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << "\n";

    return 0;
}
