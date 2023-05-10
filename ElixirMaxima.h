/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: ElixirMaxima Header File
 **************************************************/

#ifndef ELIXIRMAXIMA_H
#define ELIXIRMAXIMA_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Consumable.h"
#include "Player.h"


using namespace std;

// ElixirMaxima Class
class ElixirMaxima : public Consumable {

public:
	// constructor
	ElixirMaxima();
	~ElixirMaxima();
	void use(Player* player);
};


#endif

