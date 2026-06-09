// Binary Tree Creation without Recursion — predefined Queue
#include<iostream>
#include<queue>
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

    // ── Creation using predefined queue ──────────────
    Node* create() {
        queue<Node*> q;
        int data;

        cout << "Enter root value (-1 for no node): ";
        cin  >> data;
        if (data == -1) return nullptr;

        root = new Node(data);
        q.push(root);               // enqueue root

        while (!q.empty()) {
            Node* current = q.front();  q.pop();  // dequeue

            // ── left child ──────────────────────────────
            cout << "Enter left  child of " << current->data << " (-1 for no node): ";
            cin  >> data;
            if (data != -1) {
                current->left = new Node(data);
                q.push(current->left);
            }

            // ── right child ─────────────────────────────
            cout << "Enter right child of " << current->data << " (-1 for no node): ";
            cin  >> data;
            if (data != -1) {
                current->right = new Node(data);
                q.push(current->right);
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
