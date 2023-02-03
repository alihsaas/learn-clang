#include "stdio.h"

// a = 97, z = 122

int main()
{
	int characters[100];
	int repetitions[122 - 97 + 1] = {0};

	for (int index = 0; index < 100; index++) {
		char temp;
		do {
			scanf("%c", &temp);
		} while (temp < 97 || temp > 122);
		characters[index] = temp;
		repetitions[temp-97]++;
	}

	for (int index = 97; index <= 122; index++) {
		printf("%c %d\n", index, repetitions[index-97]);
	}
 
	return 0;
}