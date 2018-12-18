#include "Game12.h"

gameBoardSettings * initialisationBoard()
{
	// Allocation des parametres du board
	gameBoardSettings * gB = calloc(1, sizeof(gameBoardSettings));

	// Place les graines sur le board
	for (int i = 0; i < 12; i++)
	{
		gB->board[i] = 4;
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
	player->score1 = 0;
	player->playerTurn = 0;
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

	printf("|       |       |       |       |       |       |\n");
	printf("|   %d   |   %d   |   %d   |   %d   |   %d   |   %d   |\n", gameBoard->board[0], gameBoard->board[1], gameBoard->board[2], gameBoard->board[3], gameBoard->board[4], gameBoard->board[5]);
	printf("|       |       |       |       |       |       |\n");

	printf(" ");
	for (int i = 0; i < 15; i++)
	{
		printf("---");
	}
	printf("--\n");

	printf("|       |       |       |       |       |       |\n");
	printf("|   %d   |   %d   |   %d   |   %d   |   %d   |   %d   |\n", gameBoard->board[11], gameBoard->board[10], gameBoard->board[9], gameBoard->board[8], gameBoard->board[7], gameBoard->board[6]);
	printf("|       |       |       |       |       |       |\n");

	printf(" ");
	for (int i = 0; i < 15; i++)
	{
		printf("---");
	}
	printf("--\n");
}

void seeding(gameBoardSettings * gameBoard, playerSettings * player)
{

	int seedInHand = 0;
	int holeChosen = 0;
	int i = 1;
	int playerTurn = 0;


	playerTurn = 1 - playerTurn;

	// Selection de la case de 1 à 6
	scanf("%d", &holeChosen);

	// Vérification si le trou choisit est entre 1 et 6
	if (holeChosen > 6 || holeChosen < 1)
	{
		printf("Veuillez choisir un chiffre entre 1 et 6 \n");
		scanf("%d", &holeChosen);
	}

	// Replacement sur l'intervalle 0 à 5
	holeChosen -= 1;

	// Récupération des graines dans la "main"
	seedInHand = gameBoard->board[holeChosen];

	// Mise à 0 du trou sélectionner
	gameBoard->board[holeChosen] = 0;



	if (seedInHand == 0) {
		printf("Vous ne pouvez pas choisir une case ne possédant pas de graines\n");
	}
	while (seedInHand != 0)
	{
		// Retour au début du tableau
		if (i == 11)
			i = 0;

		// Distribution des graines 
		gameBoard->board[(holeChosen + i)] += 1;
		i++;
		seedInHand -= 1;
	}

	if (gameBoard->board[(holeChosen + i)] >= 2 && gameBoard->board[(holeChosen + i)] <= 3)
	{
		player->score1 = gameBoard->board[(holeChosen + i)];
		gameBoard->board[(holeChosen + i)] = 0;
		i--;
		while (gameBoard->board[(holeChosen + i)] >= 2 && gameBoard->board[(holeChosen + i)] <= 3)
		{
			player->score1 = gameBoard->board[(holeChosen + i)];
			gameBoard->board[(holeChosen + i)] = 0;
			i--;
		}

	}
	gameBoard->turn++;
}