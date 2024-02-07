#include <stdio.h>
void sort(int *A, int N) {
    int i, j, temp;
    do {
        j = 0;
        for (i = 0; i < N - 1; i++) {
            // Compare adjacent elements and swap them if they are in the wrong order
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                j++;
            }
        }
    } while (j != 0);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 25};  // Including duplicate value (25)
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, n);


    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
