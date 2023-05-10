/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Sword Class Definition File
 **************************************************/

#include "Sword.h"

 // Constructor
Sword::Sword() {
	name = "Sword";
	type = ItemType::WEAPON;
	damage = (int)WeaponDamage::SWORD;
	unlimitedUses = bool(1);
}

// Destructor
Sword::~Sword() {}