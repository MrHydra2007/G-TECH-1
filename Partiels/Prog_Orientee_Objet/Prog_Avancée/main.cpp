#include<iostream>
#include"Character.h"
#include"Warrior.h"
#include"Mage.h"

int main()
{
	Warrior warrior("Bjorn", 30, 30);
	Mage mage("Eldrin", 30, 30);

	std::cout << "Debut du combat!" << std::endl;

	do {
		warrior.Attack(mage);
		mage.TakeDamage(10);

		mage.Attack(warrior);
		warrior.TakeDamage(6);

	} while (warrior.GetHp() <= 0 || mage.GetHp() <= 0);

	std::cout << "Le combat terine." << std::endl;
	return 0;
}