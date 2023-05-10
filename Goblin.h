/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Goblin Header File
 **************************************************/

#ifndef GOBLIN_H
#define GOBLIN_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"
#include "LeatherArmour.h"
#include "Sword.h"


using namespace std;

// Goblin Class
class Goblin : public Monster {

public:
	// constructor
	Goblin();
	~Goblin();
	void setDrops();

};
#endif
