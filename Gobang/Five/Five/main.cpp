#include "five.h"
bool GAMEOVER = false;
bool INPUT = false;
int five[17][17][3] = {0}; //Player is 1
int playerx, playery;
int WINNER;

// ����0
// ��Ե��-1
// 

// дע�Ͱ�дע�Ͱ���дע���Լ���������������
// ����ֻ��Player1��Ч

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
	// ����ʼ������
	// ��ѭ����ʼ



	while (!GAMEOVER) {
		system("cls");
		print("\n");
		draw();



		// ��һ����
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
		// ������
		five[playerx][playery][0] = 1;
		five[playerx][playery][1] = 1;
		judge(1);
		forb(1);
		// ������Ҫ�޸�
		if (GAMEOVER)	break;

		INPUT = false;
		system("cls");
		print("OK, you choose (%d, %d).", playerx, playery);
		draw();

		forb(2);
		AI();
		judge(2);
	}

	// ��ѭ���Ѿ�������
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