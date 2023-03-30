#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define WIDTH (SIZE * 2)

#define BG_WHITE "\x1b[7m"
#define NORMAL "\x1b[m"

typedef struct {
	char name;
	int blocks[SIZE];
} Tower;


Tower towers[3];
int N;
int step = 0;

int size(Tower *tower) {
	int s = 0;
	for (int i = 0; i < SIZE; i++) {
		if (tower->blocks[i] == 0) break;
		s++;
	}
	return s;
}

void push(int block, Tower *tower) {
	tower->blocks[size(tower)] = block;
}

int pull(Tower *tower) {
	int temp = tower->blocks[size(tower)-1];
	tower->blocks[size(tower)-1] = 0;
	return temp;
}

void displaytower(Tower tower, int N) {
	for (int i = N + 2; i >= 0; i--) {
		for (int j = 0; j <= WIDTH; j++) {
			if (i < N && abs((WIDTH/2) - j) < tower.blocks[i]) {
				j == (WIDTH/2) ? printf("%s%d%s", BG_WHITE, tower.blocks[i], NORMAL) : printf("%s %s", BG_WHITE, NORMAL);
			} else {
				printf("%c", j == (WIDTH/2) ? '|' : ' ');
			}
		}
		printf("\n");
	}
}

void movetower(int block, Tower *from, Tower *to, Tower *middle) {
	if (block == 0) return;

	movetower(block - 1, from, middle, to);
	printf("STEP %d: MOVE %d FROM %c to %c\n", ++step, block, from->name, to->name);
	push(block, to);
	pull(from);

	printf("TOWER A\n");
	displaytower(towers[0], N);
	printf("TOWER B\n");
	displaytower(towers[1], N);
	printf("TOWER C\n");
	displaytower(towers[2], N);
	printf("ENTER ANY KEY TO CONTINUE");

	char step;
	fflush(stdin);
	scanf("%c", &step);
	movetower(block - 1, middle, to, from);
}

int main() {

	towers[0].name = 'A';
	towers[1].name = 'B';
	towers[2].name = 'C';

	printf("ENTER NUMBER OF BLOCKS (MAX %d)\n", SIZE);
	do {
		scanf("%d", &N);
	} while (N <= 0 || N > SIZE);

	for (int i = 0; i < N; i++) {
		towers[0].blocks[i] = N-i;
	}

	for (int i = 0; i < N; i++) {
		towers[1].blocks[i] = 0;
		towers[2].blocks[i] = 0;
	}

	movetower(N, &towers[0], &towers[2], &towers[1]);

}