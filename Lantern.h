/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Lantern Header File
 **************************************************/

#ifndef LANTERN_H
#define LANTERN_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"


using namespace std;

// Lantern Class
class Lantern : public Item {

public:
	// constructor
	Lantern();
	~Lantern();
	void use();
};

#endif
