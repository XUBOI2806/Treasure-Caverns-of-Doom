/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Map Class Definition File
 **************************************************/

#include "Map.h"

 // Constructor
Map::Map() {
	name = "Map";
	type = ItemType::ITEM;
	unlimitedUses = bool(1);
}

// Destructor
Map::~Map() {}

