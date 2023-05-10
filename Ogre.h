/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Ogre Header File
 **************************************************/

#ifndef OGRE_H
#define OGRE_H

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

// Ogre Class
class Ogre : public Monster {

public:
	// constructor
	Ogre();
	~Ogre();
	void setDrops();
};



#endif
