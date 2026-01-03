#include "Character.h"
#include "Item.h"

int main()
{
	// Utilisation d'objets normaux au lieu de pointeurs (plus simple et plus sûr)
	Character player(3, 5, "Manolo");

	// Les méthodes AddItem et DisplayInventory sont maintenant statiques
	// Pas besoin de créer un objet Item pour les utiliser
	Item::AddItem("Epee en bois", 3);
	Item::AddItem("Potion de soin", 5);

	player.DisplayStats();
	player.heal(7);
	Item::DisplayInventory();
	player.DisplayStats();

	return 0;
}