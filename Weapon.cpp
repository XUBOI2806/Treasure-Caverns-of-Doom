/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Weapon Class Definition File
 **************************************************/

#include "Weapon.h"

 // Constructor
Weapon::Weapon() {
	name = "Weapon";
	type = ItemType::WEAPON;
	damage = 0;
	unlimitedUses = bool(1);
}

// Destructor
Weapon::~Weapon() {}

// Gets the damage of the weapon
int Weapon::getDamage() {
	return damage;
}