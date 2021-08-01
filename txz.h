#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "windows.h"
#include "mmsystem.h"
#include "graphics.h"

#include"game1.h"
#include"game2.h"
#include"game3.h"
#include"mes1.h"
#include"mes2.h"
#include"initgame.h"

#pragma comment(lib, "winmm.lib")

void Create1(int map1[7][10]);
void DrawMap1(int map1[7][10]);
int PlayGame1(int map1[7][10]);

void Create2(int map2[7][7]);
void DrawMap2(int map2[7][7]);
int PlayGame2(int map2[7][7]);

void Create3(int map3[9][8]);
void DrawMap3(int map3[9][8]);
int PlayGame3(int map3[9][8]);

void ShowMessage1();
void ShowMessage2();

void InitGame();
char menu();