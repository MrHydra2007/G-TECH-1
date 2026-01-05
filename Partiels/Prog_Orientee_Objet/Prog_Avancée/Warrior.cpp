#include "Warrior.h"

void Warrior::Attack(Character& target)
{
	std::cout << name << " attaque avec l'epee" << std::endl;
}

void Warrior::TakeDamage(int amount)
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
