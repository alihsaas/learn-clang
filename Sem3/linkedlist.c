#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int v;
	struct Node *node;
} Node;

/** 
 	Creates a Linked List
*/
void InsertNode(Node **root, int x) {
	if (*root == NULL) {
		*root = (Node*)malloc(sizeof(Node));
		(*root)->v = x;
		(*root)->node = NULL;
	} else InsertNode(&(*root)->node, x);
}

void DisplayList(Node *root) {
	if (root == NULL) return;
	printf("%d-> ", root->v);
	DisplayList(root->node);
}