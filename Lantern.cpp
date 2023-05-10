/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Lantern Class Definition File
 **************************************************/

#include "Lantern.h"

 // Constructor
Lantern::Lantern() {
	name = "Lantern";
	type = ItemType::ITEM;
	uses = 120;
}

// Destructor
Lantern::~Lantern() {}

// Use lantern and reduce uses
void Lantern::use() {
	uses -= (rand() % 3 + 2);
}