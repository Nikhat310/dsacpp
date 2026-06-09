// Binary Tree Creation by using Recursion
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

// ── BinaryTree ───────────────────────────────────────
class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }

    // ── Recursive creation ───────────────────────────
    Node* create() {
        int data;
        cout << "Enter node value: ";
        cin  >> data;

        Node* node = new Node(data);

        int n;
        cout << "Enter number of children (0/1/2) of " << data << ": ";
        cin  >> n;

        if (n == 1) {
            cout << "Enter left child of " << data << "\n";
            node->left = create();
        }
        else if (n == 2) {
            cout << "Enter left child of " << data << "\n";
            node->left  = create();
            cout << "Enter right child of " << data << "\n";
            node->right = create();
        }

        return node;
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
