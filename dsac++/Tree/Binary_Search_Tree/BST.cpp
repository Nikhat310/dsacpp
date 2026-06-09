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

// ── Insert ───────────────────────────────────────────
Node* insert(Node* root, int data) {
    if (root == nullptr) return new Node(data);
    if      (data < root->data) root->left  = insert(root->left,  data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// ── Inorder traversal ────────────────────────────────
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// ── Find minimum node in right subtree ───────────────
Node* findMin(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

// ── Delete node (all 3 cases) ────────────────────────
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if      (key < root->data) root->left  = deleteNode(root->left,  key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Case 1: leaf node (no children)
        if (root->left == nullptr && root->right == nullptr) {
            cout << "Deleting leaf node (no child): " << root->data << "\n";
            delete root;
            return nullptr;
        }
        // Case 2: one child (only right)
        if (root->left == nullptr) {
            cout << "Deleting node with one child: " << root->data << "\n";
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: one child (only left)
        else if (root->right == nullptr) {
            cout << "Deleting node with one child: " << root->data << "\n";
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: two children
        cout << "Deleting node with two children: " << root->data << "\n";
        Node* temp  = findMin(root->right);  // inorder successor
        root->data  = temp->data;             // copy successor value
        root->right = deleteNode(root->right, temp->data); // delete successor
    }
    return root;
}

// ── main ─────────────────────────────────────────────
int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    cout << "Original BST (Inorder):\n";
    inorder(root);
    cout << "\n\n";

    // Case 1: Delete leaf node (20)
    root = deleteNode(root, 20);
    cout << "After deleting leaf node 20:\n";
    inorder(root);
    cout << "\n\n";

    // Case 2: Delete node with one child (30 now has only right child 40)
    root = deleteNode(root, 30);
    cout << "After deleting node with one child 30:\n";
    inorder(root);
    cout << "\n\n";

    // Case 3: Delete node with two children (50)
    root = deleteNode(root, 50);
    cout << "After deleting node with two children 50:\n";
    inorder(root);
    cout << "\n";

    return 0;
}
