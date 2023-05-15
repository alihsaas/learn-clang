#include <stdio.h>

#define size 10

void findMinMax(float arr[], int n, float *max, float *min)
{
    *max = arr[0];
    *min = arr[0];

    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main()
 {
    float arr[size];
    printf("Enter %d real numbers:\n", size);
    int i;
    for (i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
    }

    float max, min;
    findMinMax(arr, size, &max, &min);

    printf("Maximum value: %f\n", max);
    printf("Minimum value: %f\n", min);

    return 0;
}
