#include <stdlib.h>

typedef struct treeNode {

    int data;

    struct treeNode* left;

    struct treeNode* right;
} treeNode;
 
// Utility function to print
// the inorder traversal of the BST.

void inorder(treeNode* root)
{

    if (root != NULL) {

        inorder(root->left);

        printf("%d \n", root->data);

        inorder(root->right);

    }
}
 
// Utility function to insert
// nodes into our BST

treeNode* insert(treeNode* root, int key)
{

    // Check if tree is empty

    if (root == NULL) {

        treeNode* temp;

        temp = (treeNode*)malloc(sizeof(treeNode));

        temp->data = key;

        temp->left = NULL;

        temp->right = NULL;

        return temp;

    }

    if (key < root->data) {
 

        // if the key to be inserted

        // is lesser than the root,

        // insert into the left subtree,

        // and recursively call

        // the insert function with the

        // root->left as the new root.

        root->left = insert(root->left, key);

    }

    else {
 

        // if the key to be inserted

        // is greater than the root,

        // insert into the right subtree,

        // and recursively call

        // the insert function with the

        // root->right as the new root.

        root->right = insert(root->right, key);

    }

    return root;
}
 
// Iterative Function to delete
// 'key' from the BST.

treeNode* deleteIterative(treeNode* root, int key)
{
    treeNode* current = root, *parent;

    while (curr != NULL && current->data != key) {
        parent = current;
        if (current->data < key)
            current = current->right;
        else
            current = current->left;
    }

    if (curr == NULL) return;

    if (current->left == NULL || current->right == NULL) {
        treeNode* newCurrent;
        if (current->left == NULL)
            newCurrent = current->right;
        else
            newCurrent = current->left;

        if (parent == NULL) {
            return newCurrent;
        }

        if (parent->left == current)
            parent->left = newCurrent;
        else
            parent->right = newCurrent;
        free(current);
    } else {
        treeNode* successor, successorParent;
        successor = root->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent == NULL) {
            current->right = successor->right;
        } else {
            successorParent->left = successor->right;
        }
        current->data = successor->data;
        free(successor);
    }
    return root;
}
 
// Driver Code

int main()
{

    /*

         10

        /  \

       7    15

      / \   / \

      5  8 11 18
 

    */

    treeNode* root = NULL;

    root = insert(root, 10);

    root = insert(root, 7);

    root = insert(root, 5);

    root = insert(root, 8);

    root = insert(root, 15);

    root = insert(root, 11);

    root = insert(root, 18);
 

    cout << "Inorder traversal "

         << "of original BST:\n";

    inorder(root);

    cout << '\n';
 

    // delete node with data value 11 (leaf)

    root = deleteIterative(root, 11);

    cout << "\nDeletion of 11\n";

    cout << "Inorder traversal post deletion:\n";

    inorder(root);

    cout << '\n';
 

    // delete node with data value 15

    // (internal node with one child)

    root = deleteIterative(root, 15);

    cout << "\nDeletion of 15\n";

    cout << "Inorder traversal post deletion:\n";

    inorder(root);

    cout << '\n';
 

    // delete node with data value 10

    // (root, two children)

    root = deleteIterative(root, 10);

    cout << "\nDeletion of 10\n";

    cout << "Inorder traversal post deletion:\n";

    inorder(root);

    cout << '\n';
 

    return 0;
}
