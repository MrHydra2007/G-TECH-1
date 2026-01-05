#pragma once
#include"Character.h"

class Mage : public Character
{
public:
	Mage(std::string n, int health, int maxHealth) : Character(n, health, maxHealth) {}

	void Attack(Character& target) override;
	void TakeDamage(int amount) override;
};

