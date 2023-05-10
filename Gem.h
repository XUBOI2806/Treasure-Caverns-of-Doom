/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Gem Header File
 **************************************************/

#ifndef GEM_H
#define GEM_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"


using namespace std;

// Gem Class
class Gem : public Item {

private:
	int g_amount;

public:
	// constructor
	Gem();
	Gem(int amount);
	~Gem();

	friend bool isEqual(Gem& g1, Gem& g2);
	friend int operator+(const Gem& g1, const Gem& g2);
	friend ostream& operator<<(ostream& os, const Gem& gem);
};

#endif

