#include <stdio.h>

int main()
{
	int smallest, smallest2;

	scanf("%d", &smallest);
	scanf("%d", &smallest2);

	int inputted = 0;
	while (inputted < 98) {
		int input;
		scanf("%d", &input);

		if (input < smallest) {
			if (smallest < smallest2) {
				smallest2 = smallest;
			}
			smallest = input;
		} else if (input < smallest2) {
			if (smallest2 < smallest) {
				smallest = smallest2; 
			}
			smallest2 = smallest;
		}
		inputted++;
	}

	printf("%d, %d", smallest, smallest2);

	return 0;
}