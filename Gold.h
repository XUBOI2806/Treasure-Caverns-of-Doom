/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Gold Header File
 **************************************************/

#ifndef GOLD_H
#define GOLD_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"


using namespace std;

// Gold Class
class Gold : public Item {

private:
	int g_amount;

public:
	// constructor
	Gold();
	Gold(int amount);
	~Gold();

	friend bool isEqual(Gold& g1, Gold& g2);
	friend int operator+(const Gold& g1, const Gold& g2);
	friend int operator-(const Gold& g1, const Gold& g2);
	friend ostream& operator<<(ostream& os, const Gold& gold);

};

#endif
