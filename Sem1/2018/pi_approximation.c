#include <stdio.h>

int main()
{
	double pi = 2, term;
	int current = 1;
	do {
		int N = current * 2;
		term = (N * N)/(double)((N-1)*(N+1));
		pi *= term;
		current++;
	} while (term > 1+1e-9);
	printf("%f", pi);
	return 0;
}