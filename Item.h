/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Item Header File
 **************************************************/

#ifndef ITEM_H
#define ITEM_H

 // All #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Enums.h"

using namespace std;

// Item Class
class Item {

	// Private attributes
protected:
	string name;
	ItemType type;
	int uses;
	bool unlimitedUses;

	// Public methods
public:
	// Constructors and Destructors
	Item();
	Item(string newName, ItemType newType, int newUses);
	Item(string newName, ItemType newType, bool newUnlimitedUses);
	~Item();

	// Accessor methods
	virtual string getName();
	virtual int getUses();
	virtual ItemType getItemType();
	virtual string getUnlimitedUses();

	// Mutator methods
	virtual void setName(string newName);
	virtual void setType(ItemType newType);
	virtual void setUses(int newUses);
	virtual void setUnlimitedUses(bool newUnlimitedUses);

	// Methods
	virtual void use();
	virtual void getDetails();
	virtual void testItem();
};

#endif

