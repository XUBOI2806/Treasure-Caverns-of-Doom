/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: BalthazarsSpellTome Header File
 **************************************************/

#ifndef BALTHAZARSSPELLTOME_H
#define BALTHAZARSSPELLTOME_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"


using namespace std;

// BalthazarsSpellTome Class
class BalthazarsSpellTome : public Item {

public:
	// constructor
	BalthazarsSpellTome();
	~BalthazarsSpellTome();
};

#endif


