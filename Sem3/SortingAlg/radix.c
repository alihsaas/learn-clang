#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void SortUpRadixArray(int *inputArray, int arraySize) {
    int maxElement = inputArray[0], i, j = 1, **binaryRepresentation, k, l, m, temp, **zeroBits, **oneBits, zeroCount, oneCount;

    // Find the maximum element in the array
    for (i = 1; i < arraySize; i++) {
        if (maxElement < inputArray[i]) {
            maxElement = inputArray[i];
        }
    }

    // Calculate the number of bits required for the binary representation
    for (i = 2; i <= maxElement; i *= 2) {
        j++;
    }

    // Allocate memory for binary representation arrays
    binaryRepresentation = (int **)malloc(arraySize * sizeof(int *));
    zeroBits = (int **)malloc(arraySize * sizeof(int *));
    oneBits = (int **)malloc(arraySize * sizeof(int *));

    for (i = 0; i < arraySize; i++) {
        *(binaryRepresentation + i) = (int *)malloc(j * sizeof(int));
        *(zeroBits + i) = (int *)malloc(j * sizeof(int));
        *(oneBits + i) = (int *)malloc(j * sizeof(int));
    }

    // Convert each element to its binary representation
    for (i = 0; i < arraySize; i++) {
        temp = inputArray[i];
        for (k = j - 1; k >= 0; k--) {
            if (temp >= pow(2, k)) {
                binaryRepresentation[i][k] = 1;
                temp -= pow(2, k);
            } else {
                binaryRepresentation[i][k] = 0;
            }
        }
    }

    // Perform radix sort
    for (i = 0; i < j; i++) {
        zeroCount = oneCount = 0;
        for (k = 0; k < arraySize; k++) {
            if (binaryRepresentation[k][i] == 0) {
                for (l = 0; l < j; l++) {
                    zeroBits[zeroCount][l] = binaryRepresentation[k][l];
                }
                zeroCount++;
            } else {
                for (l = 0; l < j; l++) {
                    oneBits[oneCount][l] = binaryRepresentation[k][l];
                }
                oneCount++;
            }
        }

        for (k = 0; k < zeroCount; k++) {
            for (l = 0; l < j; l++) {
                binaryRepresentation[k][l] = zeroBits[k][l];
            }
        }

        m = k;

        for (k = 0; k < oneCount; k++) {
            for (l = 0; l < j; l++) {
                binaryRepresentation[m][l] = oneBits[k][l];
            }
            m++;
        }
    }

    // Convert binary representation back to decimal
    for (i = 0; i < arraySize; i++) {
        inputArray[i] = 0;
        for (k = 0; k < j; k++) {
            inputArray[i] += binaryRepresentation[i][k] * pow(2, k);
        }
    }

    // Free allocated memory
    for (i = 0; i < arraySize; i++) {
        free(binaryRepresentation[i]);
        free(zeroBits[i]);
        free(oneBits[i]);
    }
    free(binaryRepresentation);
    free(zeroBits);
    free(oneBits);
}

// Function to print an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    SortUpRadixArray(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
