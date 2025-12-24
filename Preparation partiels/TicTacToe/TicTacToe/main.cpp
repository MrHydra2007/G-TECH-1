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
	// TODO: Demander au joueur d'entrer les coordonnées de sa prochaine case (ligne et colonne)
	// Assurez-vous que les entrées sont valides (0, 1 ou 2)

	// BONUS:
	// Proposez une méthode pour gérer les entrées invalides (saisie de caractère non numérique)
}

// EX7
void GetComputerMove(int* row, int* col)
{
	// TODO: Générer des coordonnées aléatoires pour la prochaine case de l'ordinateur en utilisant la fonction rand()

	int random = rand() % 3; // génère un nombre aléatoire entre 0 et 2

	// BONUS:
	// Proposez un algorithme plus optimisé pour choisir aléatoirement la prochaine case de l'ordinateur
	// Faites toutes les modifications que vous jugez nécessaires sur l'architecture déjà en place
}

int main() 
{
	srand(time(NULL)); // initialisation du générateur de nombres aléatoires

	// EX8
	// TODO: Implémenter la boucle du jeu de morpion en utilisant les fonctions précédentes
	// La boucle doit alterner entre le joueur et l'ordinateur jusqu'à ce qu'il y ait un gagnant ou que la grille soit pleine
	// Afficher la grille après chaque coup
	
	return 0;
}