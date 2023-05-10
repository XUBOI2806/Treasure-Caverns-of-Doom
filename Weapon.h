/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Weapon Header File
 **************************************************/

#ifndef WEAPON_H
#define WEAPON_H

 // All #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Enums.h"
#include "Item.h"

using namespace std;

// Item Class
class Weapon : public Item {

	// Private attributes
protected:
	int damage;

	// Public methods
public:
	// Constructors and Destructors
	Weapon();
	~Weapon();
	virtual int getDamage();
};

#endif
