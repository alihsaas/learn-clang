void sort(int *A, int N) {
    int i, j, m, T;

    // Outer loop: Iterate through each element in the array except the last one
    for (i = 0; i < N - 1; i++) {
        m = i; // Assume the current index is the minimum

        // Inner loop: Find the index of the minimum element in the unsorted portion
        for (j = i + 1; j < N; j++) {
            if (A[m] > A[j]) {
                m = j; // Update the index of the minimum element
            }
        }

        // Swap the minimum element with the first unsorted element
        if (i != m) {
            T = A[i];
            A[i] = A[m];
            A[m] = T;
        }
    }
}

#include <stdio.h>

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call Sort_Succ_Min_Array to sort the array
    sort(arr, n);

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
