/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 2
  Author: Felix Xu
  Purpose: Monster Header File
 **************************************************/

#ifndef HEADER_H
#define GOLD_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"


using namespace std;

// Player Class
class Gold : public Item {

public:
	// constructor
	Gold();
	~Gold();
};

#endif
