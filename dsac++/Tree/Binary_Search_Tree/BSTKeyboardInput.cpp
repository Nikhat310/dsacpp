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
    else cout << "Duplicate value " << data << " ignored.\n";
    return root;
}

// ── Traversals ───────────────────────────────────────
void inorder(Node* root) {
    if (root) { inorder(root->left); cout << root->data << " "; inorder(root->right); }
}
void preorder(Node* root) {
    if (root) { cout << root->data << " "; preorder(root->left); preorder(root->right); }
}
void postorder(Node* root) {
    if (root) { postorder(root->left); postorder(root->right); cout << root->data << " "; }
}

// ── Search ───────────────────────────────────────────
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return search(root->left,  key);
    return                       search(root->right, key);
}

// ── Find minimum (used in delete case 3) ─────────────
Node* findMin(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

// ── Delete ───────────────────────────────────────────
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) { cout << "Value " << key << " not found.\n"; return nullptr; }

    if      (key < root->data) root->left  = deleteNode(root->left,  key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Case 1: leaf node
        if (root->left == nullptr && root->right == nullptr) {
            cout << "Deleting leaf node (no child): " << root->data << "\n";
            delete root; return nullptr;
        }
        // Case 2: one child
        if (root->left == nullptr) {
            cout << "Deleting node with one child: " << root->data << "\n";
            Node* temp = root->right; delete root; return temp;
        }
        if (root->right == nullptr) {
            cout << "Deleting node with one child: " << root->data << "\n";
            Node* temp = root->left; delete root; return temp;
        }
        // Case 3: two children — replace with inorder successor
        cout << "Deleting node with two children: " << root->data << "\n";
        Node* temp  = findMin(root->right);
        root->data  = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ── Menu ─────────────────────────────────────────────
void printMenu() {
    cout << "\n===== BST MENU =====\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Inorder   (L-Root-R)\n";
    cout << "5. Preorder  (Root-L-R)\n";
    cout << "6. Postorder (L-R-Root)\n";
    cout << "7. Exit\n";
    cout << "Enter choice: ";
}

// ── main ─────────────────────────────────────────────
int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        printMenu();
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin  >> value;
                root = insert(root, value);
                cout << value << " inserted.\n";
                break;

            case 2:
                if (!root) { cout << "Tree is empty.\n"; break; }
                cout << "Enter value to delete: ";
                cin  >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin  >> value;
                if (search(root, value))
                    cout << value << " found in BST.\n";
                else
                    cout << value << " not found in BST.\n";
                break;

            case 4:
                if (!root) { cout << "Tree is empty.\n"; break; }
                cout << "Inorder   : "; inorder(root);   cout << "\n";
                break;

            case 5:
                if (!root) { cout << "Tree is empty.\n"; break; }
                cout << "Preorder  : "; preorder(root);  cout << "\n";
                break;

            case 6:
                if (!root) { cout << "Tree is empty.\n"; break; }
                cout << "Postorder : "; postorder(root); cout << "\n";
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
