#include <stdio.h>

int main() {
	char string[10][101];
	int string_len[10] = {0};
	int longest_string_index = 0;
	

	for (int i = 0; i < 10; i++) {
		gets(string[i]);
		for (int j = 0; j < 100; j++) {
			if (string[i][j] == '\0') break;
			string_len[i]++;
		}
		if (string_len[longest_string_index] < string_len[i]) longest_string_index = i;
	}
	int k = 0;
	for (int i = string_len[longest_string_index] - 1; i >= -1; i--) {
		k++;
		if (string[longest_string_index][i] == ' ' || i == -1) {
			for (int current = i + 1; current < i + k;  current++) {
				printf("%c", string[longest_string_index][current]);
			}
			printf(" ");
			k = 0;
		}
	}

	return 0;
}