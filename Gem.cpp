/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Gem Class Definition File
 **************************************************/

#include "Gem.h"

 // Constructor
Gem::Gem() {
	name = "Gem";
	type = ItemType::ITEM;
	unlimitedUses = bool(1);
	g_amount = 0;
}

// Constructor
Gem::Gem(int amount) {
	name = "Gem";
	type = ItemType::ITEM;
	unlimitedUses = bool(1);
	g_amount = amount;
}

// Destructor
Gem::~Gem() {}

// For adding gems
int operator+(const Gem& g1, const Gem& g2) {
	return g1.g_amount + g2.g_amount;
}

// Display information
ostream& operator<<(ostream& os, const Gem& gem) {
	os << " You have in total " << gem.g_amount << " gems";
	return os;
}