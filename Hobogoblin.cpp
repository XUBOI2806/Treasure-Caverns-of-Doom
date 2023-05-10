/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Hobogoblin Class Definition File
 **************************************************/

#include "Hobogoblin.h"

 // Constructor
Hobogoblin::Hobogoblin() {
	name = "Hobogoblin";
	level = 2;
	health = level * (rand() % 2 + 3);
	attack = level + (rand() % 2 + 2);
	defence = level + (rand() % 2 + 1);
	damage = level + (rand() % 1 + 1);
	setDrops();
	dropPercent = 50;
}

// Destructor
Hobogoblin::~Hobogoblin() {}

// Sets the drops
void Hobogoblin::setDrops() {
	int rng = rand() % 101;
	int rng2 = rand() % 2;
	if (rng <= 50) {
		vector<Item*> newDrops;
		if (rng2 == 0) {
			newDrops.push_back(new LeatherArmour());
			drops = newDrops;
		}
		else {
			newDrops.push_back(new Sword());
			drops = newDrops;
		}
	}
}
