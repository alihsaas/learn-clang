#include <stdio.h>

#define SIZE 10

int main()
{
	int integers_A[SIZE];

	printf("enter value 0\n");
	scanf("%d", &integers_A[0]);
	int min_position = 0, max_position = 0;
	int min = integers_A[0], max = integers_A[0];

	for (int i = 1; i < SIZE; i++) {
		fflush(stdin);
		printf("enter value %d\n", i);
		scanf("%d", &integers_A[i]);
		if (min > integers_A[i]) {
			min = integers_A[i];
			min_position = i;
		}
		if (max < integers_A[i]) {
			max = integers_A[i];
			max_position = i;
		}
	}

	printf("MAX is %d at %d\nMIN is %d at %d", max, max_position, min, min_position);

	return 0;
}
