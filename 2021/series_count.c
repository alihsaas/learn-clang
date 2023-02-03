#include <stdio.h>

int main()
{
	int nb_of_series = 1;
	int temp, inputted = 0;
	scanf("%d", &temp);

	while (inputted < 14) {
		int input;
		scanf("%d", &input);
		if (input < temp) nb_of_series++;
		inputted++;
		temp = input;
	}

	printf("%d", nb_of_series);

	return 0;
}