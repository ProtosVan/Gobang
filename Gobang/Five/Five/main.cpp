#include "five.h"
bool GAMEOVER = false;
bool INPUT = false;
int five[17][17][3] = {0}; //Player is 1
int playerx, playery;
int WINNER;

// 写注释啊写注释啊不写注释自己都看不懂！！！
// 禁手只对Player1有效

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
	// ↑初始化棋盘
	// 主循环开始
	while (!GAMEOVER) {
		system("cls");
		print("\n");
		draw();
		// 画一画啦
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
		// 落子了
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
		judge(2);
		forb();
	}

	// 主循环已经结束了
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