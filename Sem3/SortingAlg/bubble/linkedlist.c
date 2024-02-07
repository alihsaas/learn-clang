#include "../../linkedlist.c"

void sort(Node** root) {
    int i, j, T;
    do {
        j = 0;
        Node *current = *root;
        while (current != NULL && current->node != NULL) {
            if (current->v > current->node->v) {
                T = current->v;
                current->v = current->node->v;
                current->node->v = T;
                j++;
            }
            current = current->node;
        }
    } while (j!=0);
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
