/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: ElixirMaxima Class Definition File
 **************************************************/

#include "ElixirMaxima.h"

 // Constructor
ElixirMaxima::ElixirMaxima() {
	name = "Elixir Maxima";
	type = ItemType::ARTEFACT;
	uses = 1;
}

// Destructor
ElixirMaxima::~ElixirMaxima() {}

// Use consumable on player
void ElixirMaxima::use(Player* player) {
	cout << "You got poisioned and instantly die!";
	player->setHealth(0);
}