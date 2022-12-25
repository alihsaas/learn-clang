#include <stdio.h>
#include <stdbool.h>

static int VALID_NUMBERS[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

bool search_array(const int* array, int target) {
	bool result = false;

	for (int index = 0; index < 9; index++) {
		if (array[index] == target) {
			result = true;
			break;
		}
	}

	return result;
}

int len(const int* array) {
	int count = 0;

	for (int index = 0; index < 9; index++) {
		if (array[index] == 0) break;
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	
	int grid[9][9] = {
		{ 3, 6, 0, /**/  0, 0, 7, /**/  0, 0, 2},
		{ 0, 0, 0, /**/  8, 0, 0, /**/  0, 7, 6},
		{ 0, 0, 0, /**/  0, 5, 0, /**/  1, 4, 0},
		////////////////////////////////////////
		{ 0, 3, 0, /**/  7, 0, 0, /**/  9, 0, 0},
		{ 9, 7, 2, /**/  0, 0, 0, /**/  5, 8, 3},
		{ 0, 0, 1, /**/  0, 0, 5, /**/  0, 2, 0},
		////////////////////////////////////////
		{ 0, 1, 8, /**/  0, 3, 0, /**/  0, 0, 0},
		{ 6, 4, 0, /**/  0, 0, 8, /**/  0, 0, 0},
		{ 2, 0, 0, /**/  1, 0, 0, /**/  0, 9, 8}
	};

	for (int _ = 0; _ < 10; _++) {
		for (int chunk_y = 0; chunk_y < 3; chunk_y++) {
			for (int chunk_x = 0; chunk_x < 3; chunk_x++) {
				for (int current_row = 0; current_row < 3; current_row++) {
					for (int current_column = 0; current_column < 3; current_column++) {
						int scaled_row = 3 * chunk_y + current_row;
						int scaled_column = 3 * chunk_x + current_column;

						int not_valid_numbers[9] = {};

						if (grid[scaled_row][scaled_column] == 0) {
							for (int column = 0; column < 9; column++) {
								int value = grid[scaled_row][column];
								printf("[%d %d] -> %d\n", scaled_row, column, value);
								if (!search_array(not_valid_numbers, value)) {
									not_valid_numbers[len(not_valid_numbers)] = value;
								}
							}

							for (int index = 0; index < len(not_valid_numbers); index++) {
								printf("%d ", not_valid_numbers[index]);
							}
							printf("\n");

							for (int row = 0; row < 9; row++) {
								int value = grid[row][scaled_column];
								printf("[%d %d] -> %d\n", row, scaled_column, value);
								if (!search_array(not_valid_numbers, value)) {
									not_valid_numbers[len(not_valid_numbers)] = value;
								}
							}

							for (int index = 0; index < len(not_valid_numbers); index++) {
								printf("%d ", not_valid_numbers[index]);
							}
							printf("\n");

							for (int row = 0; row < 3; row++) {
								for (int column = 0; column < 3; column++) {
									int scaled_row_2 = 3 * chunk_y + row;
									int scaled_column_2 = 3 * chunk_x + column;
									int value = grid[scaled_row_2][scaled_column_2];
									printf("[%d %d] -> %d\n", scaled_row_2, scaled_column_2, value);
									if (!search_array(not_valid_numbers, value)) {
										not_valid_numbers[len(not_valid_numbers)] = value;
									}
								}
							}

							for (int index = 0; index < len(not_valid_numbers); index++) {
								printf("%d ", not_valid_numbers[index]);
							}
							printf("\n");

							int valid_numbers[9] = {};

							for (int index = 0; index < 9; index++) {
								if (!search_array(not_valid_numbers, VALID_NUMBERS[index])) {
									valid_numbers[len(valid_numbers)] = VALID_NUMBERS[index];
								}
							}

							for (int index = 0; index < len(valid_numbers); index++) {
								printf("%d ", valid_numbers[index]);
							}
							printf("-->> [%d, %d]\n", scaled_row, scaled_column);
							if (len(valid_numbers) == 1) {
								grid[scaled_row][scaled_column] = valid_numbers[0];
							}
						}
					}
				}
			}
		}
	}

	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {
			printf("%d ", grid[row][column]);
		}
		printf("\n");
	}

	return 0;
}