#include "five.h"
bool GAMEOVER = false;
bool INPUT = false;
int five[17][17][3] = {0}; //Player is 1
int playerx, playery;
int WINNER;

void main(void) {
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			five[i][j][0] = 0;
			five[i][j][1] = 0;
			five[i][j][2] = 0;
			if (i == 0 || i == 16 || j == 0 || j == 16) {
				five[i][j][0] = -1;
				five[i][j][1] = -1;
				five[i][j][2] = -1;
			}
		}
	}
	while (!GAMEOVER) {
		system("cls");
		print("\n");
		draw();
		while (!INPUT) {
			scanf("%d %d", &playerx, &playery);
			if (five[playerx][playery][0] > 0) {
				system("cls");
				print("There already existed a chess piece.\n");
				draw();
			}
			else
				INPUT = true;
		}
		five[playerx][playery][0] = 1;
		five[playerx][playery][1] = 1;
		judge(1);
		if (GAMEOVER)	break;
		INPUT = false;
		system("cls");
		print("OK, you choose (%d, %d).", playerx, playery);
		draw();
		forb();
		AI();
		forb();
	}
	if (WINNER = 1) {
		system("cls");
		print("You win!\n");
		system("pause");
	}
	else {
		system("cls");
		print("You lose.\n");
		system("pause");
	}
}