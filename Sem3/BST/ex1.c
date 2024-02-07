#include <stdio.h>
#include <malloc.h>

typedef struct BSTNode {
	int value;
	struct BSTNode* leftNode;
	struct BSTNode* rightNode;
} BSTNode;

void CREATE_BST_ITER(BSTNode** root, int x) {
	if (*root == NULL) {
		*root = (BSTNode*)malloc(sizeof(BSTNode));
		(*root)->value = x;
	} else {
		BSTNode* parent = *root;

		while (parent != NULL) {
			if (x <= parent->value) {
				if (parent->leftNode != NULL) {
					parent = parent->leftNode;
				} else {
					parent->leftNode = (BSTNode*)malloc(sizeof(BSTNode));
					parent->leftNode->value = x;
					parent = NULL;
				}
			} else {
				if (parent->rightNode != NULL) {
					parent = parent->rightNode;
				} else {
					parent->rightNode = (BSTNode*)malloc(sizeof(BSTNode));
					parent->rightNode->value = x;
					parent = NULL;
				}
			}
		}
	}
}

void CREATE_BST_RECURSIVE(BSTNode** root, int x) {
	if (*root == NULL) {
		*root = (BSTNode*)malloc(sizeof(BSTNode));
		(*root)->value = x;
	} else {
		if (x <= (*root)->value) {
			CREATE_BST_RECURSIVE(&(*root)->leftNode, x);
		} else {
			CREATE_BST_RECURSIVE(&(*root)->rightNode, x);
		}
	}
}

BSTNode* SEARCH_BST_ITER(BSTNode** root, int x) {
	if (*root == NULL) return NULL;

	BSTNode* parent = *root;
	while (parent != NULL) {
		if (x == parent->value) return parent;
		if (x < parent->value) {
			if (parent->leftNode != NULL) {
				parent = parent->leftNode;
			} else return NULL;
		} else {
			if (parent->rightNode != NULL) {
				parent = parent->rightNode;
			} else return NULL;
		}
	}
	return NULL;
}

BSTNode* SEARCH_BST_RECURSIVE(BSTNode** root, int x) {
	if (*root == NULL) return NULL;
	if ((*root)->value == x) return *root;
	return SEARCH_BST_RECURSIVE((*root)->value < x ? &(*root)->leftNode : &(*root)->rightNode, x);
}