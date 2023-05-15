#include <stdio.h>

int main()
{
	char currency[6][8] = {"Dollar", "Half", "Quarter", "Dime", "Nickel", "Penny"};
	int values[6]       = {  100   ,   50  ,    25    ,   10  ,    5    ,    1   };

	float temp;
	scanf("%f", &temp);
	int input = temp * 100;

	for (int current = 0; current < 6; current++) {
		int remained = input % values[current];
		int value = input - remained;
		int final = value/values[current];
		if (final != 0) {
			printf("%d %s ", final, currency[current]);
		}
		input -= value;
	}

	return 0;
}