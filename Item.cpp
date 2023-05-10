/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Item Class Definition File
 **************************************************/

#include "Item.h"

 // Constructor
Item::Item() {
	name = "";
	type = ItemType::ITEM;
	uses = 0;
	unlimitedUses = bool(0);
}

// Overloaded Constructor with limited uses
Item::Item(string newName, ItemType newType, int newUses) {
	setName(newName);
	setType(newType);
	setUses(newUses);
	unlimitedUses = bool(0);
}

// Overloaded Constructor with unlimited uses
Item::Item(string newName, ItemType newType, bool newUnlimitedUses) {
	setName(newName);
	setType(newType);
	uses = 0;
	setUnlimitedUses(newUnlimitedUses);
}

// Destructor
Item::~Item() {}

// Retrieves the name of the item
string Item::getName() {
	return name;
}

// Returns the item type as a string
ItemType Item::getItemType() {
	return type;
}

// Returns the amount of uses the item has left
int Item::getUses() {
	return uses;
}

// Retrieving if the item has unlimited uses or not
string Item::getUnlimitedUses() {
	if (unlimitedUses == 1) {
		return "True";
	}
	else {
		return "False";
	}
}

// Sets the name of the item
void Item::setName(string newName) {
	name = newName;
}

// Sets the type of the item
void Item::setType(ItemType newType) {
	type = newType;
}

// Sets the amount of uses the item has
void Item::setUses(int newUses) {
	uses = newUses;
}

// Sets the amount of uses the item has
void Item::setUnlimitedUses(bool newUnlimitedUses) {
	unlimitedUses = newUnlimitedUses;
}

// Use item
void Item::use() {}

// display Item details
void Item::getDetails() {
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// access Name Test
	cout << "\n Item Name: " << getName();
	// access Uses Test
	cout << "\n Item Uses: " << getUses();
	// access Uses Test
	cout << "\n Item Unlimited Uses: " << getUnlimitedUses();
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

// Item test
void Item::testItem() {

	Item newItem01;
	newItem01.getDetails();
	Item newItem02("Leather Armour", ItemType::ARMOUR, bool(1));
	newItem02.getDetails();
	Item newItem03("Provisions", ItemType::POTION, 2);
	newItem03.getDetails();
}