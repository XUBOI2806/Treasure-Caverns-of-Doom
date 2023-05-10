/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Gold Class Definition File
 **************************************************/

#include "Gold.h"

 // Constructor
Gold::Gold() {
	name = "Gold";
	type = ItemType::ITEM;
	unlimitedUses = bool(1);
	g_amount = 0;
}

// Constructor
Gold::Gold(int amount) {
	name = "Gold";
	type = ItemType::ITEM;
	unlimitedUses = bool(1);
	g_amount = amount;
}

// Destructor
Gold::~Gold() {}

// For adding gold
int operator+(const Gold& g1, const Gold& g2) {
	return g1.g_amount + g2.g_amount;
}

// For removing golf
int operator-(const Gold& g1, const Gold& g2) {
	return g1.g_amount - g2.g_amount;
}

// Display information
ostream& operator<<(ostream& os, const Gold& gold) {
	os << " You have in total " << gold.g_amount << " gold";
	return os;
}
