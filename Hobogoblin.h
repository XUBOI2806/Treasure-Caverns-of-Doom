/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Hobogoblin Header File
 **************************************************/

#ifndef HOBOGOBLIN_H
#define HOBOGOBLIN_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"
#include "LeatherArmour.h"
#include "Sword.h"


using namespace std;

// Hobogoblin Class
class Hobogoblin : public Monster {

public:
	// constructor
	Hobogoblin();
	~Hobogoblin();
	void setDrops();
};

#endif
