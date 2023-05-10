/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: BootsOfSpeed Header File
 **************************************************/

#ifndef BOOTSOFSPEED_H
#define BOOTSOFSPEED_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Armour.h"


using namespace std;

// BootsOfSpeed Class
class BootsOfSpeed : public Armour {

public:
	// constructor
	BootsOfSpeed();
	~BootsOfSpeed();
};

#endif
