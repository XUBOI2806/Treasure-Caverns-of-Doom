/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Goblin Class Definition File
 **************************************************/

#include "Goblin.h"

 // Constructor
Goblin::Goblin() {
	name = "Goblin";
	level = 1;
	health = level * (rand() % 1 + 2);
	attack = level + (rand() % 2 + 1);
	defence = level + (rand() % 1 + 1);
	damage = level;
	setDrops();
	dropPercent = 40;
}

// Destructor
Goblin::~Goblin() {}

// Sets the drops
void Goblin::setDrops() {
	int rng = rand() % 101;
	int rng2 = rand() % 2;
	if (rng <= 40) {
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