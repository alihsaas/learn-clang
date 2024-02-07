#include <stdio.h>
#include <stdlib.h>
int* sort(int N) {
    int i, *A = (int*)malloc(N * sizeof(int)), X, j, k;

    for (i = 0; i < N; i++) {
        printf("A[%d] = ", i + 1);
        scanf("%d", &X);

        for (j = 0; j < i; j++) {
            if (X < A[j])
                break;
        }

        for (k = i; k > j; k--) {
            printf("%d %d\n", j, k);
            A[k] = A[k - 1];
        }

        A[j] = X;
    }

    return A;
}

int main() {
    int N;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    // Call Sort_Rank_Array to get a sorted array
    int *sortedArray = sort(N);

    // Print the sorted array
    printf("\nSorted Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sortedArray[i]);
    }

    // Free the dynamically allocated memory
    free(sortedArray);

    return 0;
}
