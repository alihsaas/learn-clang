#include <stdio.h>
#include <stdlib.h>

void direct_merge_sort(int *A, int N) {
    int i, *P = (int *)malloc(N * sizeof(int)), *Q = (int *)malloc(N * sizeof(int));
    int np, nq, j = 2, k = 1, m, n, f, l = 0, c;

    while (k <= N) {
        i = 0;
        l = 0;
        np = nq = 0;

        // Divide the elements into P and Q alternatively
        while (i < N) {
            for (j = 0; j < k && i < N; j++) {
                if (l % 2 == 0)
                    P[np++] = A[i++];
                else
                    Q[nq++] = A[i++];
            }
            l++;
        }

        i = m = n = 0;

        // Merge the elements from P and Q back into A
        while (m < np) {
            j = i;

            // Merge elements from P
            for (c = 0; c < k && m < np; c++) {
                A[i++] = P[m++];
            }

            // Merge elements from Q
            for (c = 0; c < k && n < nq; c++) {
                while (A[j] < Q[n] && j < i) {
                    j++;
                }
                if (j < i) {
                    // Shift elements to make space for Q[n]
                    for (f = i; f >= j; f--) {
                        A[f] = A[f - 1];
                    }
                    A[j] = Q[n];
                    i++;
                    n++;
                } else {
                    // If j >= i, simply copy the remaining elements from Q
                    A[i++] = Q[n++];
                }
            }
        }

        k *= 2;
    }

    // Free dynamically allocated memory
    free(P);
    free(Q);
}

int main() {
    int my_array[] = {4, 1, 2, 7, 5, 8, 1, 3, 9, 6};
    int array_size = 10;

    printf("Original array: ");
    for (int i = 0; i < array_size; i++)
        printf("%d ", my_array[i]);
    printf("\n");

    // Perform merge sort with separation into increasing chains
    direct_merge_sort(my_array, array_size);

    printf("Sorted array: ");
    for (int i = 0; i < array_size; i++)
        printf("%d ", my_array[i]);
    printf("\n");

    return 0;
}