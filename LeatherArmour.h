/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: LeatherArmour Header File
 **************************************************/

#ifndef LEATHERARMOUR_H
#define LEATHERARMOUR_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Armour.h"


using namespace std;

// LeatherArmour Class
class LeatherArmour : public Armour {

public:
	// constructor
	LeatherArmour();
	~LeatherArmour();
};

#endif
