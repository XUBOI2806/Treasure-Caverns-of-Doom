/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Provisions Header File
 **************************************************/

#ifndef PROVISIONS_H
#define PROVISIONS_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Consumable.h"
#include "Player.h"


using namespace std;

// Provisions Class
class Provisions : public Consumable {

public:
	// constructor
	Provisions();
	~Provisions();
	void use(Player* player);
};

#endif
