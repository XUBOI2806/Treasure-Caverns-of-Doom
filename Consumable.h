/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Consumable Header File
 **************************************************/

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

 // All #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Enums.h"
#include "Item.h"
#include "Player.h"

using namespace std;

// Item Class
class Consumable : public Item {

	// Public methods
public:
	virtual void use(Player* player);
};

#endif

