/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Troll Class Definition File
 **************************************************/

#include "Troll.h"

 // Constructor
Troll::Troll() {
	name = "Troll";
	level = 4;
	health = level * (rand() % 2 + 5);
	attack = level + (rand() % 3 + 4);
	defence = level + (rand() % 3 + 2);
	damage = level + (rand() % 2 + 2);
	setDrops();
	dropPercent = 70;
}

// Destructor
Troll::~Troll() {}

// Sets the drops
void Troll::setDrops() {
	int rng = rand() % 101;
	int rng2 = rand() % 4;
	if (rng <= 70) {
		vector<Item*> newDrops;
		switch (rng2) {
		case 0:
		{
			newDrops.push_back(new KrangsBattleAxe());
			drops = newDrops;
			break;
		}
		case 1:
		{
			newDrops.push_back(new KrangsChainmail());
			drops = newDrops;
			break;
		}
		case 2:
		{
			newDrops.push_back(new BootsOfSpeed());
			drops = newDrops;
			break;
		}
		case 3:
		{
			newDrops.push_back(new ElixirMaxima());
			drops = newDrops;
			break;
		}
		}
	}
}