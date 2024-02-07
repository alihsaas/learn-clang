#include "../../linkedlist.c"
#include <stdio.h>

void sort(Node** root) {
    int T;
    Node *current = *root;

    while (current != NULL) {
        Node* variable = current->node;
        Node* min = current;
        while (variable != NULL) {
            if (min->v > variable->v) min = variable;
            variable = variable->node;
        }
        if (min != current) {
            int T = current->v;
            current->v = min->v;
            min->v = T;
        }
        current = current->node;
    }
}

int main() {
    Node *root = NULL;

    // Insert elements into the binary search tree
    InsertNode(&root, 5);
    InsertNode(&root, 3);
    InsertNode(&root, 8);
    InsertNode(&root, 2);
    InsertNode(&root, 4);
    InsertNode(&root, 7);
    InsertNode(&root, 9);

    printf("Original Tree: ");
    DisplayList(root);
    printf("\n");

    sort(&root);

    printf("Sorted Array: ");
    DisplayList(root);
    printf("\n");

    // Free the allocated memory
    free(root);

    return 0;
}
