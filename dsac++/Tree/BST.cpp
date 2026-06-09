#include <stdio.h>
#include <stdlib.h>

// Define structure for BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find minimum node in right subtree
Node* findMin(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Delete node from BST with comments for all 3 cases
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        // Case 1: No child (leaf)
        if (root->left == NULL && root->right == NULL) {
            printf("Deleting leaf node (no child): %d\n", root->data);
            free(root);
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL) {
            printf("Deleting node with one child: %d\n", root->data);
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            printf("Deleting node with one child: %d\n", root->data);
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        printf("Deleting node with two children: %d\n", root->data);
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy inorder successor value
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }

    return root;
}

// Main function
int main() {
    Node* root = NULL;
    int i;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values)/sizeof(values[0]);

    // Insert values
    for (i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Original BST (Inorder):\n");
    inorder(root);
    printf("\n\n");

    // Case 1: Delete leaf node (20)
    root = deleteNode(root, 20);
    printf("After deleting leaf node 20:\n");
    inorder(root);
    printf("\n\n");

    // Case 2: Delete node with one child (30 has only right child 40 now)
    root = deleteNode(root, 30);
    printf("After deleting node with one child 30:\n");
    inorder(root);
    printf("\n\n");

    // Case 3: Delete node with two children (50)
    root = deleteNode(root, 50);
    printf("After deleting node with two children 50:\n");
    inorder(root);
    printf("\n");

    return 0;
}