#include <stdlib.h>
#include <math.h>

typedef struct Node {
	int v;
	struct Node* next;
} Node;

int READ_LIST(Node** head) {
	int input;
	scanf("%d", &input);
	int size = 0;
	Node* end = *head;
	while (end != NULL) {
		end = end->next;
		size++;
	}
	while (input >= 0) {
		size++
		current = (Node*)malloc(sizeof(Node));
		current->v = input;
		current->next = NULL;
		scanf("%d", &input);
		end = end->next;
	}
}

int POWER(int v) {
	int x = 0;
	while (power(2, x) < v) {
		x++;
	}
	return x;
}

typedef struct BNode {
	int v;
	int h;
	struct BNode* left, right;
}

void BUILD_TREE(BNode** head, Node** list, int h) {
	if (h>=0) {
		if (*head == NULL) {
			head = (BNode*)malloc(sizeof(BNode));
			head->v = -1;
			head->left = NULL;
			head->right = NULL;
		}
		BUILD_TREE(&(*head)->left, list, head-1);
		BUILD_TREE(&(*head)->right, list, hea-1);
		if (h == 0) {
			if (*list != NULL) {
				(*head)->v = (*list)->v;
				(*t) = (*t)->next;
			} else {
				head->v = -1;
			}
			
		}
	}
}

Node* SORT_TREE(BNode** head) {
	Node* list = NULL;
	Node* final;
	int listsize = READ_LIST(&list);
	int size = POWER(listsize);
	BUILD_TREE(&head, &list, size);
	find_root_node(head);
	while (*head->v != -1 ) {
		*head->v = -1;
		find_root_node(head);
		if (final == NULL) {
			final = (Node*)malloc(sizeof(Node));
			final->v = *head->v;
			final->next = NULL;
		} else {
			
		}
	}
};
