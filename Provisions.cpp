/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Provisions Class Definition File
 **************************************************/

#include "Provisions.h"

 // Constructor
Provisions::Provisions() {
	name = "Provisions";
	type = ItemType::POTION;
	uses = rand() % 2 + 2;
}

// Destructor
Provisions::~Provisions() {}

// Use item on player
void Provisions::use(Player* player) {
	int healAmount = rand() % 6 + 5;
	player->heal(healAmount);
	uses -= 1;
	cout << " Provisions uses left: " << uses << endl;
}