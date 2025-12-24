#include "Grid.h"

#include <iostream>

// EX1
void Initialize(Grid* grid) 
{
	// TODO: Initialiser la grille en mettant des espaces dans toutes les cellules
}

// EX2
void Print(const Grid* grid) 
{
	system("cls"); // rafraissement d'écran

	// TODO: Afficher la grille dans la console

	// Exemple d'affichage attendu :
	// [ ][ ][ ]
	// [ ][X][ ]
	// [O][ ][ ]
}

// EX3
bool SetCell(Grid* grid, int row, int col, char symbol) 
{
	// TODO: Mettre à jour la cellule spécifiée avec le symbole donné
	// Assurez vous que la cellule choisie soit vide 
	// Retourner true si c'est le cas, sinon false
}

// EX4
bool IsWin(const Grid* grid, char symbol) 
{
	// TODO: Vérifier si le symbole donné a une ligne gagnante dans la grille (horizontale, verticale ou diagonale)
	// Retourner true si le symbole a gagné, sinon false
}

// EX5
bool IsFull(const Grid* grid) 
{
	// TODO: Vérifier si toutes les cellules de la grille sont remplies
	// Retourner true si la grille est pleine, sinon false

	//BONUS : 
	// proposer une méthode plus optimisée pour savoir quand la grille est pleine
	// Faites toutes les modifications que vous jugez nécessaires sur l'architecture déjà en place
}
