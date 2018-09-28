#pragma once
#include <cstdio>
#include <cstdlib>

#pragma warning(disable: 4996)
#define print printf

void draw(void);// »­ÆåÅÌ
void judge(int players);// ÅĞ¶ÏÊ¤¸º
void AI(void);// Âä×ÓAI
void forb(void);// ½ûÊÖ

extern int WINNER;
extern bool GAMEOVER;
extern bool INPUT;
extern int five[17][17][3];
extern int playerx, playery;