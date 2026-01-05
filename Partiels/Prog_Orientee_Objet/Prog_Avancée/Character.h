#pragma once
#include<iostream>
#include<string>
class Character
{
protected:
	std::string name;
	int hp;
	int maxHp;
public:

	Character(std::string n, int health, int maxHealth) : name(n), hp(health), maxHp(maxHealth) {}

	virtual void Attack(Character& target) = 0;
	virtual void TakeDamage(int amount) = 0;

	const int GetHp() { return hp; }

};

