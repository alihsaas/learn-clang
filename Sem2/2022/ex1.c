#include <stdio.h>

void Read(int *x) {
	do {
		scanf("%d", x);
	} while (*x <= 0);
}

int Prod(int x, int y) {
	int min, max;
	int product = 1;

	if (x > y) {
		min = y;
		max = x;
	} else {
		min = x;
		max = y;
	}

	for (int i = min; i <= max; i++) {
		product *= i;
	}

	return product;
}

int C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    
    int numerator = Prod(n - k + 1, n);
    int denominator = Prod(1, k);
    
    return numerator / denominator;
}

void Print(int x) {
	printf("(a + b)^%d = ", x);
	printf("%da^%d", 1, x);
	for (int i = 1; i < x; i++) {
		printf("+ %da^%db^%d", C(x, i), x-i, x);
	}
	printf("+ %db^%d", 1, x);
}

int main(int argc, char const *argv[])
{
	int x;
	Read(&x);
	Print(x);
	return 0;
}