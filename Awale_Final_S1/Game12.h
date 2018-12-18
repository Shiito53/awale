#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct s_board
{
	int board[12];
	int turn;
	int SeedOnBoard;

}gameBoardSettings;

typedef struct s_player
{
	int score1;
	int score2;
	int playerTurn;

}playerSettings;

gameBoardSettings * initialisationBoard();
playerSettings * initialisationPlayer();
void displayBoard(gameBoardSettings * gameBoard);
int SelectGameMode();
void seeding(gameBoardSettings * gameBoard, playerSettings * player);