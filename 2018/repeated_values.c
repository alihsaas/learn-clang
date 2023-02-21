#include <stdio.h>

int main() {
	int A[10];

	for (int i = 0; i < 10; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < 10; i++) {
		int temp = i;
		for (int j = 0; j < 10; j++) {
			if (i != j && A[i] == A[j]) {
				i++;
				break;
			}
		}
		if (i==temp) {
			printf("%d\t", A[i]);	
		}
	}
}