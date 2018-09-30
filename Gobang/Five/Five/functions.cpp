#include "five.h"

//This function can draw the board.
void draw(void) {
	print("  1 2 3 4 5 6 7 8 9 0 1 2 3 4 5\n\n");
	for (int i = 1; i < 16; i++) {
		print("%d ", i % 10);
		for (int j = 1; j < 16; j++) {
			if (five[i][j][0] == 1)
				print("〇");
			else if (five[i][j][0] == 2)
				print("口");
			else if (five[i][j][0] == 0)
				print("丶");
			else if (five[i][j][0] == -2)
				print("义");
		}
		print("\n");
	}
}

//Players: 1 for human, 2 for AI.
void judge(int players) {
	int countx = 0;
	int county = 0;
	int count = 0;
	int nowx = 0;
	int nowy = 0;
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			if (five[i][j][players] == 1) {
				countx++;
				if (countx == 5) {
					GAMEOVER = true;
					WINNER = players;
				}
			}
			else county = 0;
			if (five[i][j][players] == 1) {
				county++;
				if (county == 5) {
					GAMEOVER = true;
					WINNER = players;
				}
			}
			else county = 0;
		}
		nowx = i;
		nowy = 1;
		while (true) {
			if (five[nowx][nowy][players] == -1) break;
			else {
				if (five[nowx][nowy][players] == 1) count++;
				if (count == 5) {
					GAMEOVER = true;
					WINNER = players;
				}
				if (five[nowx][nowy][players] == 0) count = 0;
				nowx++;
				nowy++;
			}
		}
		nowx = 1;
		nowy = i;
		while (true) {
			if (five[nowx][nowy][players] == -1) break;
			else {
				if (five[nowx][nowy][players] == 1) count++;
				if (count == 5) {
					GAMEOVER = true;
					WINNER = players;
				}
				if (five[nowx][nowy][players] == 0) count = 0;
				nowx++;
				nowy++;
			}
		}
		nowx = 1;
		nowy = i;
		while (true) {
			if (five[nowx][nowy][players] == -1) break;
			else {
				if (five[nowx][nowy][players] == 1) count++;
				if (count == 5) {
					GAMEOVER = true;
					WINNER = players;
				}
				if (five[nowx][nowy][players] == 0) count = 0;
				nowx--;
				nowy++;
			}
		}
		nowx = i;
		nowy = 1;
		while (true) {
			if (five[nowx][nowy][players] == -1) break;
			else {
				if (five[nowx][nowy][players] == 1) count++;
				if (count == 5) {
					GAMEOVER = true;
					WINNER = players;
				}
				if (five[nowx][nowy][players] == 0) count = 0;
				nowx--;
				nowy++;
			}
		}
	}
}

void AI(void)
{
	// AI其实做的是一个棋局判定，看不同的patterns，然后每一种pattern给一个估值。
	// 这种估值作为这个节点的收益。
	// 下一个节点是对方的收益。
	// 首先我是有很多节点的，并不能贪心，其次，对方也会
	// 但其实这个弊端太大了，首先你必须假定的是对方比你蠢。
	// 实际情况根本不可能这样
	// 但其实的话MCTS只是用来模拟的
	// 而Alpha-Beta是用来搜索的
	// 我想搜得深，那我每一层的节点要少。
	// 
	// 以最后一层的胜率作为值。
	// 找值爆搜不行
	return;
}

void forb(int players)
{
	int temp[17][4] = {0};
	int tempcount = 0;
	bool found1 = false;
	bool found2 = false;
	int x1, x2, y1, y2;
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			if (five[i][j][0] == 0) {
				
				tempcount = 0;
				for (int m = -1; m < 2; m++) {
					for (int n = -1; n < 2; n++) {
						if (five[i + m][j + n][0] == players) tempcount++;
					}
				} // 看看周围有多少棋子，如果少于两个棋子可以不用判断是否禁手
				
				if (tempcount > 1) {

					five[i][j][0] = players;

					// 四个方向都要搜索
					x1 = i;
					x2 = i;
					y1 = j;
					y2 = j;
					while (!found1 || !found2) {
						if (!found1) {
							x1--;
							if (five[x1][y1][0] == -1)	found1 = true;
							if (five[x1][y1][0] == 3 - players) found1 = true;
							if (five[x1][y1][0] == 0) {
								found1 = true;
								x1--;
							}
						}
						if (!found2) {
							x2++;
							if (five[x2][y2][0] == -1)	found1 = true;
							if (five[x2][y2][0] == 3 - players) found1 = true;
							if (five[x2][y2][0] == 0) {
								found2 = true;
								x2++;
							}
						}
					}

					for (int m = x1; m < x2 + 1; m++) temp[m - x1][0] = five[m][y1][0];

					x1 = i;
					x2 = i;
					y1 = j;
					y2 = j;
					found1 = false;
					found2 = false;
					while (!found1 || !found2) {
						if (!found1) {
							y1--;
							if (five[x1][y1][0] == -1)	found1 = true;
							if (five[x1][y1][0] == 3 - players) found1 = true;
							if (five[x1][y1][0] == 0) {
								found1 = true;
								y1--;
							}
						}
						if (!found2) {
							y2++;
							if (five[x2][y2][0] == -1)	found1 = true;
							if (five[x2][y2][0] == 3 - players) found1 = true;
							if (five[x2][y2][0] == 0) {
								found2 = true;
								y2++;
							}
						}
					}
					for (int m = y1; m < y2 + 1; m++) temp[m - y1][1] = five[x1][m][0];

					x1 = i;
					x2 = i;
					y1 = j;
					y2 = j;
					found1 = false;
					found2 = false;
					while (!found1 || !found2) {
						if (!found1) {
							x1--;
							y1--;
							if (five[x1][y1][0] == -1)	found1 = true;
							if (five[x1][y1][0] == 3 - players) found1 = true;
							if (five[x1][y1][0] == 0) {
								found1 = true;
								x1--;
								y1--;
							}
						}
						if (!found2) {
							x2++;
							y2++;
							if (five[x2][y2][0] == -1)	found1 = true;
							if (five[x2][y2][0] == 3 - players) found1 = true;
							if (five[x2][y2][0] == 0) {
								found2 = true;
								x2++;
								y2++;
							}
						}
					}
					for (int m = x1; m < x2 + 1; m++) temp[m - x1][2] = five[x1][y1 + m - x1][0];

					x1 = i;
					x2 = i;
					y1 = j;
					y2 = j;
					found1 = false;
					found2 = false;
					while (!found1 || !found2) {
						if (!found1) {
							x1--;
							y1++;
							if (five[x1][y1][0] == -1)	found1 = true;
							if (five[x1][y1][0] == 3 - players) found1 = true;
							if (five[x1][y1][0] == 0) {
								found1 = true;
								x1--;
								y1++;
							}
						}
						if (!found2) {
							x2++;
							y2--;
							if (five[x2][y2][0] == -1)	found1 = true;
							if (five[x2][y2][0] == 3 - players) found1 = true;
							if (five[x2][y2][0] == 0) {
								found2 = true;
								x2++;
								y2--;
							}
						}
					}
					for (int m = x1; m < x2 + 1; m++) temp[m - x1][3] = five[x1][y2 + m - x1][0];
					// 连搜两个0停止
					// 搜到别人的子也停止
					// 四个方向搜索完了之后放到temp数组里面
					
					
					// temp数组可以去判断棋局
					// 双活三肯定禁手
					// 双四怎么都是禁手
					// 长连肯定禁手
					// x ooo x这个是假活三，死四

					// 3 - players就是对面的棋子
					// 判断禁手
				
					if (true) five[i][j][0] = -2;
					else five[i][j][0] = 0;
				}
			}
		}
	}
	return;
}