#include <stdio.h>

#define SIZE 24

int main()
{

	float values[SIZE];
	int N;

	do scanf("%d", &N); while (N > SIZE || N < 0);

	// filling
	for (int i = 0; i < N; i++) {
		fflush(stdin);
		scanf("%f", &values[i]);
	}
	
	//sorting
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (values[j] > values[i]) {
				float temp = values[j];
				values[j] = values[i];
				values[i] = temp;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		printf("%f ", values[i]);
	}

	printf("\nMEAN IS %f", N%2 == 0 ? (values[N/2] + values[N/2 - 1])/2 : values[N/2]);

	return 0;
}