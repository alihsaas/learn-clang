#include <stdio.h>
#include <math.h>

int main() {
	int input, binary = 0, current = 0;

	do {
		scanf("%d", &input);
	} while (input < 0);

	while (input != 0) {
		binary += (input % 2) * pow(10, current++);
		input /= 2;
	}

	printf("%d", binary);

	return 0;
}