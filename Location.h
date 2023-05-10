/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Location Header File
 **************************************************/

#ifndef LOCATION_H
#define LOCATION_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Monster.h"
#include "Item.h"
#include "Player.h"

using namespace std;

// location Class
class Location {

private:
	int number;
	string name;
	string description;
	Monster* monster;
	vector<Item*> items;
	vector<char> exits;
	vector<int> exitNumbers;
	Player* thePlayer;
	bool examined;

public:
	// constructor
	Location();
	Location(int newNumber, string newName, string newDescription, vector<char> newExits, vector<int> newExitNumbers);
	Location(int newNumber, string newName, string newDescription, Monster* newMonster, vector<char> newExits, vector<int> newExitNumbers);
	Location(int newNumber, string newName, string newDescription, Monster* newMonster, vector<Item*> newItems, vector<char> newExits, vector<int> newExitNumbers);
	Location(int newNumber, string newName, string newDescription, vector<Item*> newItems, vector<char> newExits, vector<int> newExitNumbers);
	Location(int newNumber, string newName, string newDescription, vector<char> newExits, vector<int> newExitNumbers, Player* player);
	~Location();

	// accessor methods
	int getNumber();
	string getName();
	string getDescription();
	Monster* getMonster();
	vector<Item*> getItems();
	vector<char> getExits();
	vector<int> getExitNumbers();
	Player* getPlayer();
	bool getExamined();

	// mutator methods
	void setNumber(int newNumber);
	void setName(string newName);
	void setDescription(string newDescription);
	void setExits(vector<char> newExits);
	void setExitNumbers(vector<int> newExitNumbers);
	void setMonster(Monster* newMonster);
	void setItems(vector<Item*> newItems);
	void addItem(Item* newItem);
	void setPlayer(Player* player);
	void setExamined(bool boolean);
	void clearItems();
	Player* removePlayer();

	// methods
	string returnExit(string exit);
	void getDetails();
	void displayItems();
	void displayExitNumbers(vector <int> const& exitNumbers);
	void displayExits(vector <char> const& exits);
	void testLocation();
	void displayInformation();
};

#endif
