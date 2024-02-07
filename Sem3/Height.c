#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int V;
    struct Node *left,*right;
} Node;

void Insert_Rec(Node **F,int X)
{
    if(*F==NULL)
    {
        *F=(Node*)malloc(sizeof(Node));
        (*F)->V=X;
        (*F)->left=(*F)->right=NULL;
        return;
    }
    Insert_Rec((X<=(*F)->V)?&(*F)->left:&(*F)->right,X);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int Height(Node *R)
{
    if(R==NULL) return -1;
    return max(1+Height(R->left), 1+Height(R->right));
}

int main() {
    Node *root = NULL;

    // Insert elements into the binary search tree
    Insert_Rec(&root, 5);
    Insert_Rec(&root, 3);
    Insert_Rec(&root, 8);
    Insert_Rec(&root, 2);
    Insert_Rec(&root, 4);
    Insert_Rec(&root, 7);
    Insert_Rec(&root, 9);
    Insert_Rec(&root, 10);

    // Create an array to store the sorted elements
    int *sortedArray = (int *)malloc(7 * sizeof(int));

    // Populate the array with sorted elements
    printf("%d\n", Height(root));

    // Free the allocated memory
    free(sortedArray);

    return 0;
}
