// C++ program to implement optimized delete in BST.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in
* BST */
Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
Node* deleteNode(Node* root, int k)
{
	if (root == NULL) {
		return root
	}

	if (root->data < k) {
		root->right = deleteNode(root->right, k);
	} else if (root->data > k) {
		root->left = deleteNode(root->left, k);
	} else {
		if (root->left == NULL) {
			Node* successor = root->right;
			free(root);
			return successor
		} else if (root->right == NULL) {
			Node* successor = root->left;
			free(root);
			return successor;
		}

		Node* successor = root->right; *successorParent = root;
		while (successor->left != NULL) {
			successorParent = successor;
			successor = successor->left;
		}

		if (successorParent == root) {
			successorParent->right = successor->right;
		} else 
			successorParent->left = successor->right;
		root->data = successor->data;
		free(successor);
		return root;
	}
}

// Driver Code
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	Node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);

	printf("Original BST: ");
	inorder(root);

	printf("\n\nDelete a Leaf Node: 20\n");
	root = deleteNode(root, 20);
	printf("Modified BST tree after deleting Leaf Node:\n");
	inorder(root);

	printf("\n\nDelete Node with single child: 70\n");
	root = deleteNode(root, 70);
	printf("Modified BST tree after deleting single child Node:\n");
	inorder(root);

	printf("\n\nDelete Node with both child: 50\n");
	root = deleteNode(root, 50);
	printf("Modified BST tree after deleting both child Node:\n");
	inorder(root);

	return 0;
}
