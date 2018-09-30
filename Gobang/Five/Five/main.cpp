#include "five.h"
bool GAMEOVER = false;
bool INPUT = false;
int five[17][17][3] = {0}; //Player is 1
int playerx, playery;
int WINNER;

// 空是0
// 边缘是-1
// 

// 写注释啊写注释啊不写注释自己都看不懂！！！
// 禁手只对Player1有效

void main(void) {
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			five[i][j][0] = nULL;
			five[i][j][1] = nULL;
			five[i][j][2] = nULL;
			if (i == 0 || i == 16 || j == 0 || j == 16) {
				five[i][j][0] = eDGE;
				five[i][j][1] = eDGE;
				five[i][j][2] = eDGE;
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
		forb(1);
		// 以上需要修改
		if (GAMEOVER)	break;

		INPUT = false;
		system("cls");
		print("OK, you choose (%d, %d).", playerx, playery);
		draw();

		forb(2);
		AI();
		judge(2);
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