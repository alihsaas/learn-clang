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

int sort(Node *R,int *A,int i)
{
    if(R==NULL) return i;
    int j=sort(R->left,A,i);
    A[j]=R->V;
    j=sort(R->right,A,j+1);
    return j;
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

    // Create an array to store the sorted elements
    int *sortedArray = (int *)malloc(7 * sizeof(int));

    // Populate the array with sorted elements
    sort(root, sortedArray, 0);

    // Print the original tree and the sorted array
    printf("Original Tree (in-order traversal): ");
    // You can implement an in-order traversal function to print the tree

    printf("\nSorted Array: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(sortedArray);

    return 0;
}
