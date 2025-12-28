#include "Grid.h"

#include <iostream>

// ===============================
// PARTIEL - Programmation C++
// 
// Sujet : Jeu de Morpion (Tic-Tac-Toe)
// 
// Durée : 4 heures
// 
// Consignes : Compléter les fonctions manquantes pour que le jeu soit entièrement jouable.
// Faites les exercices dans l'ordre. Chaque exercice correspond à une fonction à compléter.
// Vous ne pourrez utiliser que les diapos du cours.
// 
// Conseils :
// Vous avez beaucoup de temps devant vous, prenez le temps de tester chaque fonction avant de passer à la suivante,
// et de tester le jeu dans son ensemble pour vous assurer que tout fonctionne correctement.
// ===============================

// EX6
void GetPlayerMove(int* row, int* col)
{
	// Demander au joueur d'entrer les coordonnées
	std::cout << "Votre tour (joueur X)" << std::endl;

	do {
		std::cout << "Entrez la ligne (0, 1 ou 2) : ";
		std::cin >> *row;

		// BONUS: Gestion des entrées invalides
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Entrée invalide! Veuillez entrer un nombre." << std::endl;
			*row = -1;
			continue;
		}

		if (*row < 0 || *row > 2) {
			std::cout << "Ligne invalide! Veuillez entrer 0, 1 ou 2." << std::endl;
		}
	} while (*row < 0 || *row > 2);

	do {
		std::cout << "Entrez la colonne (0, 1 ou 2) : ";
		std::cin >> *col;

		// BONUS: Gestion des entrées invalides
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Entrée invalide! Veuillez entrer un nombre." << std::endl;
			*col = -1;
			continue;
		}

		if (*col < 0 || *col > 2) {
			std::cout << "Colonne invalide! Veuillez entrer 0, 1 ou 2." << std::endl;
		}
	} while (*col < 0 || *col > 2);
}

// EX7
void GetComputerMove(int* row, int* col)
{
	// Générer des coordonnées aléatoires
	*row = rand() % 3;
	*col = rand() % 3;

	std::cout << "L'ordinateur (O) joue en position [" << *row << "][" << *col << "]" << std::endl;
}

// BONUS EX7: Pour optimiser, on pourrait créer une liste des cases vides
// et choisir aléatoirement parmi celles-ci au lieu de générer jusqu'à trouver une case vide

int main()
{
	srand(time(NULL)); // initialisation du générateur de nombres aléatoires

	// EX8: Boucle du jeu
	Grid grid;
	Initialize(&grid);

	bool gameOver = false;
	bool playerTurn = true; // true = joueur, false = ordinateur

	std::cout << "=== JEU DE MORPION ===" << std::endl;
	std::cout << "Vous jouez avec X, l'ordinateur avec O" << std::endl;
	std::cout << std::endl;

	while (!gameOver) {
		Print(&grid);

		int row, col;
		bool validMove = false;

		if (playerTurn) {
			// Tour du joueur
			do {
				GetPlayerMove(&row, &col);
				validMove = SetCell(&grid, row, col, 'X');

				if (!validMove) {
					std::cout << "Cette case est déjà occupée! Choisissez-en une autre." << std::endl;
				}
			} while (!validMove);

			// Vérifier si le joueur a gagné
			if (IsWin(&grid, 'X')) {
				Print(&grid);
				std::cout << "Félicitations! Vous avez gagné!" << std::endl;
				gameOver = true;
			}
		}
		else {
			// Tour de l'ordinateur
			std::cout << "Tour de l'ordinateur..." << std::endl;

			do {
				GetComputerMove(&row, &col);
				validMove = SetCell(&grid, row, col, 'O');
			} while (!validMove);

			// Vérifier si l'ordinateur a gagné
			if (IsWin(&grid, 'O')) {
				Print(&grid);
				std::cout << "L'ordinateur a gagné! Vous avez perdu." << std::endl;
				gameOver = true;
			}
		}

		// Vérifier si la grille est pleine (match nul)
		if (!gameOver && IsFull(&grid)) {
			Print(&grid);
			std::cout << "Match nul! La grille est pleine." << std::endl;
			gameOver = true;
		}

		// Alterner les tours
		playerTurn = !playerTurn;
	}

	std::cout << std::endl << "Appuyez sur Entrée pour quitter...";
	std::cin.ignore(10000, '\n');
	std::cin.get();

	return 0;
}