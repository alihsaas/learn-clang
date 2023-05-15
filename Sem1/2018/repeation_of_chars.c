#include <stdio.h>

int main()
{
	
	char string[100 + 1];
	int repeation['z' - 'a' + 1] = {0};

	gets(string);

	for (int i = 0; i < 100; i++) {
		if (string[i] == '\0') break;
		if (string[i] <= 'Z' && string[i] >= 'A') {
			repeation[string[i] - 'A']++;
		} else if (string[i] <= 'z' && string[i] >= 'a') {
			repeation[string[i] - 'a']++;
		}
	}

	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		if (repeation[i] > 0) printf("%c ", i + 'a');
	}
	printf("\n");
	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		if (repeation[i] > 0) printf("%d ", repeation[i]);
	}

	return 0;
}