/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Location Class Definition File
 **************************************************/

#include "Location.h"

 // Constructor
Location::Location() {
	number;
	name = "";
	description = "";
	setMonster(new Monster());
	items;
	exits;
	exitNumbers;
	thePlayer;
	examined = false;
}

// Overloaded Constructor with nothing in the room
Location::Location(int newNumber, string newName, string newDescription, vector<char> newExits, vector<int> newExitNumbers) {
	setNumber(newNumber);
	setName(newName);
	setDescription(newDescription);
	setMonster(new Monster());
	items;
	setExits(newExits);
	setExitNumbers(newExitNumbers);
	thePlayer;
	examined = false;
}

// Overloaded Constructor with Monster
Location::Location(int newNumber, string newName, string newDescription, Monster* newMonster, vector<char> newExits, vector<int> newExitNumbers) {
	setNumber(newNumber);
	setName(newName);
	setDescription(newDescription);
	setMonster(newMonster);
	items;
	setExits(newExits);
	setExitNumbers(newExitNumbers);
	thePlayer;
	examined = false;
}

// Overloaded Constructor with items
Location::Location(int newNumber, string newName, string newDescription, vector<Item*> newItems, vector<char> newExits, vector<int> newExitNumbers) {
	setNumber(newNumber);
	setName(newName);
	setDescription(newDescription);;
	setMonster(new Monster());
	setItems(newItems);
	setExits(newExits);
	setExitNumbers(newExitNumbers);
	thePlayer;
	examined = false;
}

// Overloaded Constructor with Monsters and items
Location::Location(int newNumber, string newName, string newDescription, Monster* newMonster, vector<Item*> newItems, vector<char> newExits, vector<int> newExitNumbers) {
	setNumber(newNumber);
	setName(newName);
	setDescription(newDescription);
	setMonster(newMonster);
	setItems(newItems);
	setExits(newExits);
	setExitNumbers(newExitNumbers);
	thePlayer;
	examined = false;
}

// Overloaded Constructor with player
Location::Location(int newNumber, string newName, string newDescription, vector<char> newExits, vector<int> newExitNumbers, Player* player) {
	setNumber(newNumber);
	setName(newName);
	setDescription(newDescription);
	setMonster(new Monster());
	items;
	setExits(newExits);
	setExitNumbers(newExitNumbers);
	setPlayer(player);
	examined = false;
}

// Destructor
Location::~Location() {
	for (int i = 0; i < items.size() - 1; i++) {
		delete items[i];
	}
	delete monster;
	delete thePlayer;
}

// Retrieves the number of the Location
int Location::getNumber() {
	return number;
}

// Retrieves the name of the Location
string Location::getName() {
	return name;
}

// Retrieves the description of the Location
string Location::getDescription() {
	return description;
}

// Retrieves the monster in the Location
Monster* Location::getMonster() {
	return monster;
}

// Returns the items in the Location
vector<Item*> Location::getItems() {
	return items;
}

// Retrieves the name of the Location
vector<char> Location::getExits() {
	return exits;
}

// Retrieves the exit numbers of the Location
vector<int> Location::getExitNumbers() {
	return exitNumbers;
}

// Retrieves the player of the Location
Player* Location::getPlayer() {
	return thePlayer;
}

// Retrieves if the Location has been fully examined yet or not
bool Location::getExamined() {
	return examined;
}

// Sets the number of the Location
void Location::setNumber(int newNumber) {
	number = newNumber;
}

// Sets the name of the Location
void Location::setName(string newName) {
	name = newName;
}

// Sets the description of the Location
void Location::setDescription(string newDescription) {
	description = newDescription;
}

// Sets the monster of the Location
void Location::setMonster(Monster* newMonster) {
	monster = newMonster;
}

// Sets the player of the Location
void Location::setPlayer(Player* player) {
	thePlayer = player;
}

// Sets the items of the Location
void Location::setItems(vector<Item*> newItems) {
	items = newItems;
}

// Adds an item to the Location
void Location::addItem(Item* newItem) {
	items.push_back(newItem);
}

// sets the exits of the Location
void Location::setExits(vector<char> newExits) {
	exits = newExits;
}

// set the exit numbers of the Location
void Location::setExitNumbers(vector<int> newExitNumbers) {
	exitNumbers = newExitNumbers;
}

// sets the examined status of the Location
void Location::setExamined(bool boolean) {
	examined = boolean;
}

// Clears the items of the Location
void Location::clearItems() {
	items.clear();
}

// Removes the player from the Location
Player* Location::removePlayer() {
	Player* player = thePlayer;
	thePlayer = nullptr;
	return player;
}

// Gets Location details
void Location::getDetails() {
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// access Number Test
	cout << "\n Location Number: " << getNumber();
	// access Name Test
	cout << "\n Location Name: " << getName();
	// access Descirption Test
	cout << "\n Location Description: " << getDescription();
	// access Monster Test
	cout << "\n Location Monster Name: ";
	if (monster->getName().length() == 0) {
		cout << "There is no Monster!";
	}
	else {
		cout << monster->getName();
	}
	// access Items Test
	cout << "\n Location Items: ";
	displayItems();
	// access Exits Test
	cout << "\n Location Exits: ";
	displayExits(exits);
	cout << "\n Location Exit Numbers: ";
	displayExitNumbers(exitNumbers);
	// access Player Test
	cout << "\n Location Player: ";
	if (thePlayer->getName().length() == 0) {
		cout << "There is no Player!";
	}
	else {
		cout << thePlayer->getName();
	}
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

// Displays the items in the Location
void Location::displayItems() {
	if (items.empty()) {
		cout << "There are no items!";
	}
	else {
		// using iterators to loop through characters
		vector<Item*>::const_iterator item;
		for (item = items.begin(); item != items.end(); ++item) {
			// stores dereferenced contents of the player
			Item* theItem = *item;
			cout << theItem->getName() << " ";
		}
	}
}

// Displays the exit numbers of the Location
void Location::displayExitNumbers(vector <int> const& exitNumbers) {
	for (int i = 0; i < exitNumbers.size(); i++)
		cout << exitNumbers.at(i) << ' ';
}

// Displays the exits of the Location
void Location::displayExits(vector <char> const& exits) {
	for (int i = 0; i < exits.size(); i++)
		cout << exits.at(i) << ' ';
}

// Location test
void Location::testLocation() {
	// Testing Default Constructor
	Location newLocation01;
	newLocation01.getDetails();
	vector<char> newExit = { 'N', 'W', 'E' };

	vector<int> newExitNumbers = { 10, 11, 12 };
	Location newLocation02(1, "Cave", "A cave", newExit, newExitNumbers);
	newLocation02.getDetails();

	vector<Item*> newDrops;
	Monster* newMonster = new Monster("Monster", 1, newDrops, 40);
	Location newLocation03(2, "Room", "A room", newMonster, newExit, newExitNumbers);
	newLocation03.getDetails();

	vector<Item*> newItems;
	newItems.push_back(new Item("Sword", ItemType::ITEM, bool("True")));
	newItems.push_back(new Item("Armour", ItemType::ARMOUR, bool("True")));
	newItems.push_back(new Item("Provisions", ItemType::ITEM, 4));
	Location newLocation04(3, "Jail", "A jail room", newItems, newExit, newExitNumbers);
	newLocation04.getDetails();

	Location newLocation05(4, "Jail", "A jail room", newMonster, newItems, newExit, newExitNumbers);
	newLocation05.getDetails();

	Player* newPlayer = new Player("Bob");
	Location newLocation06(5, "Room", "A room", newExit, newExitNumbers, newPlayer);
	newLocation06.getDetails();
}


void Location::displayInformation() {
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// access Name Test
	cout << "\n			" << getName();
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	// access Descirption Test
	cout << getDescription() << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}