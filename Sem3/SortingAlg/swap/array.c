void sort(int *A, int N) {
    int i, T, j;

    // Outer loop: Iterate through each element in the array except the last one
    for (i = 0; i < N - 1; i++) {
        // Inner loop: Iterate through the remaining unsorted elements
        for (j = i + 1; j < N; j++) {
            // Check if the current element is smaller than the element at index i
            if (A[j] < A[i]) {
                // Swap the elements if the condition is true
                T = A[j];
                A[j] = A[i];
                A[i] = T;
            }
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
