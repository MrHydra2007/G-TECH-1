#include "Character.h"
#include "Item.h"

int main()
{
	Character player(3, 5, "Manolo");


	Item::AddItem("Epee en bois", 3);
	Item::AddItem("Potion de soin", 5);

	player.DisplayStats();
	player.heal(7);
	Item::DisplayInventory();
	player.DisplayStats();

	return 0;
}