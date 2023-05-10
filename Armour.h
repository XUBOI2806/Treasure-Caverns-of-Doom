/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Armour Header File
 **************************************************/

#ifndef ARMOUR_H
#define ARMOUR_H

 // All #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Enums.h"
#include "Item.h"

using namespace std;

// Item Class
class Armour : public Item {

	// Private attributes
protected:
	int defence;

	// Public methods
public:
	// Constructors and Destructors
	Armour();
	~Armour();
	virtual int getDefence();
};

#endif
