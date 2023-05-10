/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Ogre Class Definition File
 **************************************************/

#include "Ogre.h"

 // Constructor
Ogre::Ogre() {
	name = "Ogre";
	level = 3;
	health = level * (rand() % 2 + 4);
	attack = level + (rand() % 2 + 3);
	defence = level + (rand() % 2 + 2);
	damage = level + (rand() % 2 + 1);
	setDrops();
	dropPercent = 60;
}

// Destructor
Ogre::~Ogre() {}

// Sets the drops
void Ogre::setDrops() {
	int rng = rand() % 101;
	int rng2 = rand() % 4;
	if (rng <= 60) {
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

