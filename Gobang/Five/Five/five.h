#pragma once
#include <cstdio>
#include <cstdlib>

#pragma warning(disable: 4996)
#define print printf
#define nULL 0
#define eDGE -1


void draw(void);// ������
void judge(int players);// �ж�ʤ��
void AI(void);// ����AI
void forb(int players);// ����

extern int WINNER;
extern bool GAMEOVER;
extern bool INPUT;
extern int five[17][17][3];
extern int playerx, playery;