/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: PostionFlask Header File
 **************************************************/

#ifndef POTIONFLASK_H
#define POTIONFLASK_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Consumable.h"
#include "Player.h"


using namespace std;

// PostionFlask Class
class PotionFlask : public Consumable {

public:
	// constructor
	PotionFlask();
	~PotionFlask();
	void use(Player* player);
};

#endif