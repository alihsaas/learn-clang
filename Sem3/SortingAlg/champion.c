#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree {
    int v;
    struct tree *left, *right;
} tree;

void makeChildren(tree *root, int n) {
    if (n>0) {
        root->left = (tree*)malloc(sizeof(tree));
        root->left->v = 0;
        root->left->left = NULL;
        root->left->right = NULL;
        root->right = (tree*)malloc(sizeof(tree));
        root->right->v = 0;
        root->right->left = NULL;
        root->right->right = NULL;
        makeChildren(root->left, n-1);
        makeChildren(root->right, n-1);
    }
}

int fillTree(tree *root, int element) {
    if (root->left != NULL) {
        if (!fillTree(root->left, element)) {
            if (!fillTree(root->right, element))
                return 0;
            else
                return 1;
        } else {
            return 1;
        }
    } else if (root->v==0) {
        root->v = element;
        return 1;
    }
    return 0;
}

tree *buildTree(int n, int *A, int size) {
    int i;
    tree *t = (tree*)malloc(sizeof(tree));
    t->v = 0;
    t->left = NULL;
    t->right = NULL;
    makeChildren(t, n);
    for (i = 0; i < size; i++) {
        fillTree(t, A[i]);
    }
    return t;
}

void champ(tree *node) {
    if (node->left != NULL) {
        if (node->left->v == 0)
            champ(node->left);
        if (node->right->v == 0)
            champ(node->right);
        if (node->left->v == 0 && node->right->v != 0) {
            node->v = node->right->v;
            node->right->v = 0;
        } else if (node->left->v != 0 && node->right->v == 0) {
            node->v = node->left->v;
            node->left->v = 0;
        } else if (node->left->v != 0 && node->right->v != 0) {
            if (node->right->v < node->left->v) {
                node->v = node->right->v;
                node->right->v = 0;
            } else {
                node->v = node->left->v;
                node->left->v = 0;
            }
        }
    }
}

int *champSort(int *A, int size) {
    int n = 0;
    while (pow(2, n) < size) {
        n++;
    }
    tree *t = buildTree(n, A, size);
    int *output = (int*)malloc(size*sizeof(int));
    int outsize = 0;
    while (1) {
        t->v = 0;
        champ(t);
        if (t->v == 0)
            break;
        output[outsize] = t->v;
        outsize++;
    }
    return output;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 25};  // Including duplicate value (25)
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int* sorted = champSort(arr, n);


    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    return 0;
}
