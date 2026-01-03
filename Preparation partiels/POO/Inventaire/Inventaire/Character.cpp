#include "Character.h"

void Character::heal(int amount)
{
	health = health + amount;

	if (health >= maxHealth)
		health = maxHealth;
}

void Character::DisplayStats()
{
	std::cout << name << " a " << health << " PV." << std::endl;
}