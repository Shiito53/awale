/*#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// COPIER COLLER /////////////////////////////////////////////////

typedef struct s_board
{
	int board[2][6];
	int turn;
	int SeedOnBoard;

}gameBoardSettings;

typedef struct s_player
{
	int score;
	int selector;

}playerSettings;

int gameMode();
gameBoardSettings * initialisation();
void displayBoard(gameBoardSettings * gameBoard);
void seeding(int selectorPlayer, gameBoardSettings* gameboard);*/