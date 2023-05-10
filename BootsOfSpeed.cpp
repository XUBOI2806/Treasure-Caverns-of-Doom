/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: BootsOfSpeed Class Definition File
 **************************************************/

#include "BootsOfSpeed.h"

 // Constructor
BootsOfSpeed::BootsOfSpeed() {
	name = "Boots of Speed";
	type = ItemType::ARTEFACT;
	defence = (int)EquipmentDefence::BOOTS_OF_SPEED;
	unlimitedUses = bool(1);
}

// Destructor
BootsOfSpeed::~BootsOfSpeed() {}

