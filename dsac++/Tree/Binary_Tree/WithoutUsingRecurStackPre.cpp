// Without Recursion — using predefined Stack (<stack>)
#include<iostream>
#include<stack>
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

    // ── Inorder: Left → Root → Right ─────────────────
    void inorder(Node* root) {
        stack<Node*> st;
        Node* current = root;

        while (current != nullptr || !st.empty()) {
            // go to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();  st.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    // ── Preorder: Root → Left → Right ────────────────
    void preorder(Node* root) {
        if (root == nullptr) return;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* current = st.top();  st.pop();
            cout << current->data << " ";
            // push right first so left is processed first
            if (current->right != nullptr)
                st.push(current->right);
            if (current->left != nullptr)
                st.push(current->left);
        }
    }

    // ── Postorder: Left → Right → Root ───────────────
    void postorder(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stack1, stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            Node* current = stack1.top();  stack1.pop();
            stack2.push(current);
            if (current->left  != nullptr) stack1.push(current->left);
            if (current->right != nullptr) stack1.push(current->right);
        }
        while (!stack2.empty()) {
            cout << stack2.top()->data << " ";
            stack2.pop();
        }
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
