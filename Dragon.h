/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Dragon Header File
 **************************************************/

#ifndef DRAGON_H
#define DRAGON_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"

using namespace std;

// Dragon Class
class Dragon : public Monster {

public:
	// constructor
	Dragon();
	~Dragon();
	int getDamage();

private:
	bool fireBreathe;
};



#endif

