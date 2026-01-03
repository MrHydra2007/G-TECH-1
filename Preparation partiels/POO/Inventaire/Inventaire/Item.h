#pragma once
#include<iostream>
#include<string>
#include<vector>

class Item
{
private:
	std::string name;
	int value;
	static std::vector<Item> Inventory;  // Inventaire partagé entre tous les items

public:
	Item(std::string n, int v) : name(n), value(v) {}

	static void AddItem(std::string name, int value);
	static void DisplayInventory();
};