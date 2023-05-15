#include <stdio.h>

int main()
{
	char paragraph[1000+1];
	char search[100+1];

	gets(paragraph);
	fflush(stdin);
	gets(search);

	for (int para_position = 0; para_position <= 1000; para_position++) {
		if (paragraph[para_position] == '\0') {
			break;
		}
		int start, end;
		int found = 0;

		for (int search_pos = 0; search_pos <= 100; search_pos++) {
			if (paragraph[para_position] == search[search_pos] && search_pos == 0) {
				start = para_position;
				continue;
			}
			if (search[search_pos] == '\0') {
				end = para_position + search_pos;
				found = 1;
				break;
			}
			if (paragraph[para_position + search_pos] != search[search_pos]) {
				break;
			}
		}
		if (found == 1) {
			printf("%d %d\n", start + 1, end + 1);
			para_position = end;
		}
	}

	return 0;
}