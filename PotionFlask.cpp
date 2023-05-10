/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: PotionFlask Class Definition File
 **************************************************/

#include "PotionFlask.h"

 // Constructor
PotionFlask::PotionFlask() {
	name = "Potion Flask";
	type = ItemType::POTION;
	uses = rand() % 2 + 1;
}

// Destructor
PotionFlask::~PotionFlask() {}

// Use item on player
void PotionFlask::use(Player* player) {
	// Gets buff amount
	int buffAmount = rand() % 3 + 2;
	// Checks if it adds or deducts stats
	if (rand() % 2 != 0) {
		cout << " You lost " << buffAmount;
		buffAmount *= -1;
	}
	else {
		cout << " You gained " << buffAmount;
	}
	// Checks what stat is to be buffed or nerfed
	int stat = rand() % 4;
	switch (stat) {
	case 0:
	{
		player->setMaxHealth(player->getMaxHealth() + buffAmount);
		player->setHealth(player->getHealth() + buffAmount);
		cout << " Max Health";
		break;
	}
	case 1:
	{
		player->setAttack(player->getAttack() + buffAmount);
		cout << " attack";
		break;

	}
	case 2:
	{
		player->setDefence(player->getDefence() + buffAmount);
		cout << " defence";
		break;
	}
	case 3:
	{
		player->setLuck(player->getLuck() + buffAmount);
		cout << " luck";
		break;
	}
	}
	cout << endl;
	uses -= 1;
	cout << " Potion uses left: " << uses << endl;
}
