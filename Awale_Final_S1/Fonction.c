#include "Header.h"
/*
// Créer et initialise le board et ses parametres
gameBoardSettings * initialisationBoard()
{
	// Allocation des parametres du board
	gameBoardSettings * gB = calloc(1, sizeof(gameBoardSettings));

	// Place les graines sur le board
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			gB->board[i][j] = 4;
		}

	}

	// Initialise les tours
	gB->turn = 0;

	// Initialise le nombre de graines présentes sur le board
	gB->SeedOnBoard = 48;

	return gB;
}

playerSettings * initialisationPlayer()
{
	playerSettings * player = calloc(1, sizeof(playerSettings));
	player->score = 0;
	player->selector = 0;
	return player;
}



// Choix du mode de jeu
int SelectGameMode()
{
	int mode = 0;

	printf("Selection du mode de jeu\n\n");

	printf("1. Player Versus IA\n");
	printf("2. Player Versus Player\n");

	scanf("%d", &mode);

	switch (mode)
	{
	case 1:
		printf("1. Mode 1 joueur choisit\n\n");
		break;

	case 2:
		printf("1. Mode 2 joueurs choisit\n\n");
		break;

	default:
		mode = 0;
		printf("Erreur: Choisissez entre le mode 1 joueur ou 2 joueur!\n\n");
		break;
	}

	return mode;

}

// Affichage du board
void displayBoard(gameBoardSettings * gameBoard)
{
	printf("Board turn %d : \n\n", gameBoard->turn);

	printf(" ");

	for (int i = 0; i < 15; i++)
	{

		printf("---");
	}

	printf("--\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("|       ");
		}
		printf("|\n");

		for (int j = 0; j < 6; j++)
		{
			printf("|   %d   ", gameBoard->board[i][j]);
		}
		printf("|\n");

		for (int j = 0; j < 6; j++)
		{
			printf("|       ");
		}
		printf("|\n");

		printf(" ");
		for (int k = 0; k < 15; k++)
		{
			printf("---");
		}
		printf("--\n");
	}


}


/*void seeding(playerSettings * player, gameBoardSettings* gameboard)
{
	int seedInHand = 0;
	int line = player->selector;
	int holeChosen = 0;
	scanf("%d", &holeChosen);

	holeChosen -= 1;

	if (holeChosen > 6 || holeChosen < 0)
	{
		printf("Veuillez choisir un chiffre entre 1 et 5");
		scanf("%d", &holeChosen);
	}

	seedInHand = gameboard->board[player->selector][holeChosen];
	gameboard->board[player->selector][holeChosen] = 0;

	int sens;
	if (line = 1) {
		sens = -1;
	}
	else {
		sens = 1;
	}

	while (seedInHand)
	{
		int i = 0;
		board[][];
	}




	/*
	if (player->selector == 0)
	{

		if (seedInHand == 0)
		{
			printf("error");
			return;
		}

		if (i > 5)
		{
			line = 1;

			for (int j = seedInHand; j > 5 - seedInHand; j--)
			{
				gameboard->board[line][j - 1] += 1;
				seedInHand -= 1;
			}

		}

		if (i < 0)
		{

		}


		for (int j = 0; j < 6; j++)
		{

		}
	}

}*/

