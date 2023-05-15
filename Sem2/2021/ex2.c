#include <stdio.h>

typedef struct {
	int factor;
	int power;
} Term;

int read_natural() {
	int i;
	do {
		scanf("%d", &i);
	} while (i < 0);
	return  i;
}

void read_natural_address(int *i) {
	do {
		scanf("%d", i);
	} while (*i < 0);
}

int prime_factors(int x, Term destination[]) {
	int number_of_terms = 0;
	for (int i = 2; i <= x; i++) {
		int is_prime = 1;
		for (int j = 2; j <= i/2; j++) {
			if (i%j == 0) {
				is_prime = 0;
				j = i/2;
			}
		}
		int temp = x;
		float y = (float)x / i;
		if (is_prime && (int)y == y) {
			destination[number_of_terms].factor = i;
			destination[number_of_terms].power = 0;
			while ((int)y == y) {
				destination[number_of_terms].power++;
				temp = temp / i;
				y = (float)temp / i;
			}
			number_of_terms++;
		}
	}
	return number_of_terms;
}

void display(int number_of_terms, Term factorization[]) {
	printf("%d^%d", factorization[0].factor, factorization[0].power);
	for (int i = 1; i < number_of_terms; i++) {
		printf(" * %d^%d", factorization[i].factor, factorization[i].power);
	}
}

int main()
{
	int x = read_natural();
	Term factors[10];
	int number_of_terms = prime_factors(x, factors);
	printf("%d = ", x);
	display(number_of_terms, factors);
	return 0;
}