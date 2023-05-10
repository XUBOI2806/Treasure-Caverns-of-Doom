/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Sword Header File
 **************************************************/

#ifndef SWORD_H
#define SWORD_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Weapon.h"


using namespace std;

// Sword Class
class Sword : public Weapon {

public:
	// constructor
	Sword();
	~Sword();
};

#endif
