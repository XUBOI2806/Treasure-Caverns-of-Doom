/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Map Header File
 **************************************************/

#ifndef MAP_H
#define MAP_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"


using namespace std;

// Map Class
class Map : public Item {

public:
	// constructor
	Map();
	~Map();
};

#endif

