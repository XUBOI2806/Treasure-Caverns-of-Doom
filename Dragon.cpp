/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Dragon Class Definition File
 **************************************************/

#include "Dragon.h"

Dragon::Dragon() {
	name = "Dragon";
	level = 5;
	health = level * (rand() % 3 + 6);
	attack = level + rand() % 5 + 6;
	defence = level + rand() % 7 + 6;
	damage = level + rand() % 3 + 4;
	dropPercent = 100;
	drops.push_back(new Item("Balthazar’s Spell Tome", ItemType::ARTEFACT, bool("True")));
	fireBreathe = false;
}

// Destructor
Dragon::~Dragon() {}


int Dragon::getDamage() {
	if (fireBreathe == false) {
		int rng = rand() % 2;
		if (rng == 0) {
			fireBreathe = true;
			cout << " The dragon used Fire Breathe!" << endl;
			int newDamage = rand() % 2 + 2;
			return (getLevel() * newDamage);
		}
	}
	return damage;
}