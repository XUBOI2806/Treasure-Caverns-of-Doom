/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Troll Header File
 **************************************************/

#ifndef TROLL_H
#define TROLL_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"
#include "Krang'sBattleAxe.h"
#include "Krang'sChainmail.h"
#include "BootsOfSpeed.h"
#include "ElixirMaxima.h"


using namespace std;

// Troll Class
class Troll : public Monster {

public:
	// constructor
	Troll();
	~Troll();
	void setDrops();

};

#endif

