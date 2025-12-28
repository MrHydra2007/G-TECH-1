#include "Grid.h"

#include <iostream>

// EX1
void Initialize(Grid* grid)
{
	// Initialiser la grille en mettant des espaces dans toutes les cellules
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid->cells[i][j] = ' ';
		}
	}
}

// EX2
void Print(const Grid* grid)
{
	system("cls"); // rafraîchissement d'écran

	// Afficher la grille dans la console
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "[" << grid->cells[i][j] << "]";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// EX3
bool SetCell(Grid* grid, int row, int col, char symbol)
{
	// Vérifier si les coordonnées sont valides
	if (row < 0 || row >= 3 || col < 0 || col >= 3) {
		return false;
	}

	// Vérifier si la cellule est vide
	if (grid->cells[row][col] == ' ') {
		grid->cells[row][col] = symbol;
		return true;
	}

	return false;
}

// EX4
bool IsWin(const Grid* grid, char symbol)
{
	// Vérifier les lignes horizontales
	for (int i = 0; i < 3; i++) {
		if (grid->cells[i][0] == symbol &&
			grid->cells[i][1] == symbol &&
			grid->cells[i][2] == symbol) {
			return true;
		}
	}

	// Vérifier les colonnes verticales
	for (int j = 0; j < 3; j++) {
		if (grid->cells[0][j] == symbol &&
			grid->cells[1][j] == symbol &&
			grid->cells[2][j] == symbol) {
			return true;
		}
	}

	// Vérifier la diagonale principale
	if (grid->cells[0][0] == symbol &&
		grid->cells[1][1] == symbol &&
		grid->cells[2][2] == symbol) {
		return true;
	}

	// Vérifier la diagonale secondaire
	if (grid->cells[0][2] == symbol &&
		grid->cells[1][1] == symbol &&
		grid->cells[2][0] == symbol) {
		return true;
	}

	return false;
}

// EX5
bool IsFull(const Grid* grid)
{
	// Vérifier si toutes les cellules sont remplies
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid->cells[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

// BONUS EX5: Pour optimiser, on pourrait ajouter un compteur de coups dans la structure Grid
// et vérifier si compteur == 9 au lieu de parcourir toute la grille