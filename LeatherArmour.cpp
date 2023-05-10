/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Monster Class Definition File
 **************************************************/

#include "LeatherArmour.h"

 // Constructor
LeatherArmour::LeatherArmour() {
	name = "Leather Armour";
	type = ItemType::ARMOUR;
	defence = (int)EquipmentDefence::LEATHER_ARMOUR;
	unlimitedUses = bool(1);
}

// Destructor
LeatherArmour::~LeatherArmour() {}