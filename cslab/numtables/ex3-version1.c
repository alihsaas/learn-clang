#include <stdio.h>
#include <stdlib.h>

#define HIGHLIGHTED "\x1b[45m"

#define FG_RED "\x1b[31m"
#define FG_GREEN "\x1b[32m"
#define FG_YELLOW "\x1b[33m"
#define FG_BLUE "\x1b[34m"

#define ROW_SIZE 3
#define COLUMN_SIZE 4

int main()
{
	int A[ROW_SIZE][COLUMN_SIZE];

	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COLUMN_SIZE; j++) {
			system("cls");
			for (int _i = 0; _i <= i; _i++) {
				for (int _j = 0; _j <= COLUMN_SIZE - 1; _j++) {
					if (i == _i && _j > j) break;
					if (i == _i && j == _j)
						printf("\x1b[5m__\x1b[m");
					else
						printf("%d ", A[_i][_j]);
				}
				printf("\n");
			}
			fflush(stdin);
			scanf("%d", &A[i][j]);
		}
	}

	char COLORS[4][8] = {FG_BLUE, FG_GREEN, FG_RED, FG_YELLOW};

	// SUM OF ROWS
	printf("SUM OF ROWS\n");
	for (int i = 0; i < ROW_SIZE; i++) {
		int sum = 0;
		printf("SUM -> ");
		for (int j = 0; j < COLUMN_SIZE; j++) {
			sum += A[i][j];
			printf("%s%d\x1b[m ", COLORS[i], A[i][j]);
		}
		printf("= %d\n", sum);
	}

	// SUM OF COLUMNS
	printf("SUM OF COLUMNS\n");
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int j = 0; j < COLUMN_SIZE; j++) {
			printf("%s%d\x1b[m ", COLORS[j], A[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < COLUMN_SIZE; j++) {
		int sum = 0;
		for (int i = 0; i < ROW_SIZE; i++) {
			sum += A[i][j];
		}
		printf("%d ", sum);
	}

	return 0;
}
