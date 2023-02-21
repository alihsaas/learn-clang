#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define HIGHLIGHTED "\x1b[4m"
#define NORMAL "\x1b[m"

int main() {

	int turn = 0;
	int is_incomplete = 9;
	int board[3][3] = {0};

	int highlighted[2] = {0, 0};
	char symbols[3] = {' ', 'X', 'O'};

	while (1) {
		system("cls");

		int is_won = 0;

		if (
			(board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
			(board[0][2] == board[1][1] && board[1][1] == board[2][0])
		) {
			is_won = board[1][1];
		}

		for (int row = 0; row < 3; row++) {
			int prev = board[row][0];
			int is_complete = 1;
			for (int column = 1; column < 3; column++) {
				if (board[row][column] != prev) is_complete = 0;
			}
			if (is_complete == 1) {
				is_won = prev;
				break;
			};
		}
		for (int column = 0; column < 3; column++) {
			int prev = board[0][column];
			int is_complete = 1;
			for (int row = 1; row < 3; row++) {
				if (board[row][column] != prev) is_complete = 0;
			}
			if (is_complete == 1) {
				is_won = prev;
				break;
			};
		}

		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				printf("%s %c %s|",
					row == highlighted[0] && column == highlighted[1] ? HIGHLIGHTED : "" ,
					symbols[board[row][column]],
					NORMAL);
			}
			printf("\n");
		}
		if (is_won != 0) {
			printf("Team %d Won!", is_won);
			break;
		};
		if (is_incomplete == 0) {
			printf("Draw!");
			break;
		}

		char x = _getch();

		if (x == 'e') break;

		switch (x) {
			case 'w':
				highlighted[0]--;
				break;
			case 's':
				highlighted[0]++;
				break;
			case 'a':
				highlighted[1]--;
				break;
			case 'd':
				highlighted[1]++;
				break;
			case 'q':
				if (board[highlighted[0]][highlighted[1]] == 0) {
					board[highlighted[0]][highlighted[1]] = turn + 1;
					turn = (turn + 1) % 2;
					is_incomplete--;
				}
				break;
		}

		switch (highlighted[0]) {
			case 3:
				highlighted[0] = 0;
				break;
			case -1:
				highlighted[0] = 2;
				break;
		}

		switch (highlighted[1]) {
			case 3:
				highlighted[1] = 0;
				break;
			case -1:
				highlighted[1] = 2;
				break;
		}
	}
}