#pragma once
#include<string>
#include<iostream>

class Character
{
private:
	int health;
	int maxHealth;
	std::string name;

public:
	Character(int hp, int MaxHp, std::string n) : health(hp), maxHealth(MaxHp), name(n) {}

	void heal(int amount);
	void DisplayStats();
};