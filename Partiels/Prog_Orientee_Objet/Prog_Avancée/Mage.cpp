#include "Mage.h"

void Mage::Attack(Character& target)
{
	std::cout << name << " lance un sort de feu!" << std::endl;
}

void Mage::TakeDamage(int amount)
{
	hp = hp - amount;

	std::cout << name << " a maintenant " << GetHp() << " PV" << std::endl;

	if (GetHp() < 0)
	{
		hp = 0;
	}

	if (GetHp() > maxHp)
		hp = maxHp;
}
