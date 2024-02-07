#include "../../linkedlist.c"
#include <stdlib.h>

void SortedInsert(Node** root, int x) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->v = x;
        (*root)->node = NULL;
    } else if ((*root)->v > x) {
        Node* new = (Node*)malloc(sizeof(Node));
        new->v = x;
        new->node = *root;
        *root = new;
    } else {
        SortedInsert(&(*root)->node, x);
    }
}

int main() {
    Node *root = NULL;

    // Insert elements into the binary search tree
    SortedInsert(&root, 5);
    SortedInsert(&root, 3);
    SortedInsert(&root, 8);
    SortedInsert(&root, 2);
    SortedInsert(&root, 4);
    SortedInsert(&root, 7);
    SortedInsert(&root, 9);

    printf("Sorted Array: ");
    DisplayList(root);
    printf("\n");

    // Free the allocated memory
    free(root);

    return 0;
}
