#include "Game12.h"
#include "AI.h"

int main()
{
	//TEST DES FONCTIONS POUR LIA
	int p_value = 2;
	sTree * tree;

	tree = Create_sTree(p_value);
	void freeNode(p_pRoot);



	/////////////////////////////

	playerSettings * player1 = NULL;
	playerSettings * player2 = NULL;

	// Selection du mode de jeu
	int gameMode = SelectGameMode();

	// Quitte le jeu si aucun mode de jeu choisit
	if (gameMode == 0)
	{
		system("PAUSE");
		return EXIT_FAILURE;
	}


	// Choix du mode 1 joueur
	if (gameMode == 1)
	{
		printf("Osef\n");

		system("PAUSE");
		return EXIT_SUCCESS;

	}

	// Choix du mode 2 joueurs
	if (gameMode == 2)
	{
		// Initialisation du joueur 1
		player1 = initialisationPlayer();

	}

	// Création du pointeur sur structure
	gameBoardSettings * gameBoard = NULL;

	// Initialisation
	gameBoard = initialisationBoard();

	// Affichage du board
	displayBoard(gameBoard);

	//seeding(player1, gameBoard);

	while (1)
	{
		// Affichage du board
		displayBoard(gameBoard);

		seeding(gameBoard, player1);
	}


	system("PAUSE");
	return 0;
}