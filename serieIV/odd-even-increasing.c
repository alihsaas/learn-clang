#include <stdio.h>

static int size = 10;

void print_array(char* string, int* arr) {
	printf("%s", string);
	for (int index = 0; index < size; index++) {
		printf("%d ", arr[index]);
	}
	printf("\n");
}

int main() {
	int odd_even[10] = {0};
	int odd_size = 0, even_size = 0;

	while (odd_size + even_size != size) {
		int input;
		scanf("%d", &input);
		if (input % 2 == 0) {
			odd_even[size - ++even_size] = input;
			int target = size - even_size;
			for (int index = target; index < size; index++) {
				if (odd_even[index] < input) {
					int temp = odd_even[index];
					odd_even[index] = odd_even[target];
					odd_even[target] = temp;
					target = index;
				}
				print_array("- ", odd_even);
			}
		} else {
			odd_even[odd_size++] = input;

			int target = odd_size - 1;
			for (int index = target; index > 0; index--) {
				if (odd_even[index] > input) {
					int temp = odd_even[index];
					odd_even[index] = odd_even[target];
					odd_even[target] = temp;
					target = index;
				}
				print_array("- ", odd_even);
			}
		}
	}

	print_array("Final ", odd_even);
}