/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Armour Class Definition File
 **************************************************/

#include "Armour.h"

 // Constructor
Armour::Armour() {
	name = "Armour";
	type = ItemType::ARMOUR;
	defence = 0;
	unlimitedUses = bool(1);
}

// Destructor
Armour::~Armour() {}

// Gets the defence
int Armour::getDefence() {
	return defence;
}