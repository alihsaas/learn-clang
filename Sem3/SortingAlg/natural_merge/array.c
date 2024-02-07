#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    int k;
    for (k=left+1; k <= right; k++) {
        if (arr[k] < arr[k-1]) break;
    }
    k--;
    if (k == right) return;

    merge_sort(arr, k+1, right);

    merge(arr, left, k, right);
}

int main() {
    int my_array[] = {6, 7, 8, 1, 2, 3, 0, 3};
    int array_size = 8;

    printf("Original array: ");
    for (int i = 0; i < array_size; i++)
        printf("%d ", my_array[i]);
    printf("\n");

    // Perform merge sort with separation into increasing chains
    merge_sort(my_array, 0, array_size-1);

    printf("Sorted array: ");
    for (int i = 0; i < array_size; i++)
        printf("%d ", my_array[i]);
    printf("\n");

    return 0;
}