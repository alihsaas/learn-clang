#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 3
#define COLUMN_SIZE 4

int main()
{
	int A[ROW_SIZE][COLUMN_SIZE];

	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COLUMN_SIZE; j++) {
			fflush(stdin);
			printf("ENTER VALUE FOR ROW %d COLUMN %d\n", i, j);
			scanf("%d", &A[i][j]);
		}
	}

	// SUM OF ROWS
	printf("SUM OF ROWS\n");
	for (int i = 0; i < ROW_SIZE; i++) {
		int sum = 0;
		for (int j = 0; j < COLUMN_SIZE; j++) {
			sum += A[i][j];
		}
		printf("SUM OF ROW %d = %d\n", i, sum);
	}

	// SUM OF COLUMNS
	printf("SUM OF COLUMNS\n");
	for (int j = 0; j < COLUMN_SIZE; j++) {
		int sum = 0;
		for (int i = 0; i < ROW_SIZE; i++) {
			sum += A[i][j];
		}
		printf("SUM OF COLUMN %d = %d\n", j, sum);
	}

	return 0;
}
