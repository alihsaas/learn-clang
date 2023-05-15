#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);
	int factors[2][10] = {{0}};
	int filled = 1;
	factors[0][0] = 1;
	factors[1][0] = 1;

	int current = 2;
	while (filled <= 10 && current < input) {
		int isPrime = 1;
		for (int i = 2; i <= current/2; i++) {
			if (current % i == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime == 1) {
			int temp = input;
			while (temp > 1 && temp % current == 0) {
				factors[0][filled] = current;
				factors[1][filled]++;
				temp /= current;
			}
			filled++;
		}
		current++;
	}
	printf("\n");
	printf("1");
	for (int index = 1; index < 10; index++) {
		for (int repet = 0; repet < factors[1][index]; repet++) {
			printf("*%d", factors[0][index]);
		}
	}

	return 0;
}