/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Player Class Definition File
 **************************************************/

#include "Player.h"

 // Constructor
Player::Player() {
	name = "";
	maxHealth = rand() % 9 + 16;
	health = maxHealth;
	attack = health / 6;
	defence = attack / 2;
	damage = attack / 3;
	luck = rand() % 5 + 8;
	gold = Gold();
	gem = Gem();
}

// Overloading Constructor
Player::Player(string inputName) {
	setName(inputName);
	maxHealth = rand() % 9 + 16;
	health = maxHealth;
	attack = health / 6;
	defence = attack / 2;
	damage = attack / 3;
	luck = rand() % 5 + 8;
	gold = Gold();
	gem = Gem();
	Item* item1 = new Lantern();
	Item* item2 = new Map();
	Item* item3 = new Sword();
	addItemToInventory(item1);
	addItemToInventory(item2);
	addItemToInventory(item3);
}

// Destructor
Player::~Player() {
	for (int i = 0; i < inventory.size() - 1; i++) {
		delete inventory[i];
	}
}

// Retrieves the name of the Player
string Player::getName() {
	return name;
}

// Retrieves the maximum health of the Player
int Player::getMaxHealth() {
	return maxHealth;
}

// Retrieves the cuurent health of the Player
int Player::getHealth() {
	return health;
}

// Retrieves if the Player is alive or not
bool Player::isAlive() {
	return health > 0;
}

// Retrieves the attack of the Player
int Player::getAttack() {
	return attack;
}

// Retrieves the defence of the Player
int Player::getDefence() {
	int totalDefence = defence;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getItemType() == ItemType::ARMOUR) {
			Armour* armour = static_cast<Armour*>(inventory[i]);
			totalDefence += armour->getDefence();
		}
	}
	return totalDefence;
}

// Retrieves the damage of the Player
int Player::getDamage() {
	int totalDamage = damage;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getItemType() == ItemType::WEAPON) {
			Weapon* weapon = static_cast<Weapon*>(inventory[i]);
			totalDamage += weapon->getDamage();
		}
	}
	return totalDamage;
}

// Retrieves the luck of the Player
int Player::getLuck() {
	return luck;
}

// Retrieves the inventory of the Player
vector<Item*> Player::getInventory() {
	return inventory;
}

// Retrieves the gold of the Player
void Player::getGold() {
	cout << gold << endl;
}

// Retrieves the gems of the Player
void Player::getGems() {
	cout << gem << endl;
}

// Sets the name of the Player
void Player::setName(string newName) {
	if (newName.length() > 0) {
		name = newName;
	}
	else {
		name = "Sir John Smith";
	}
}

// Sets the Max Health of the Player
void Player::setMaxHealth(int newMaxHealth) {
	if (newMaxHealth < 0) {
		newMaxHealth = 0;
	}
	maxHealth = newMaxHealth;
}

// Sets the health of the Player
void Player::setHealth(int newHealth) {
	if (newHealth < 0) {
		newHealth = 0;
	}
	health = newHealth;
}

// Sets the attack of the Player
void Player::setAttack(int newAttack) {
	if (newAttack < 0) {
		newAttack = 0;
	}
	attack = newAttack;
}

// Sets the defence of the Player
void Player::setDefence(int newDefence) {
	if (newDefence < 0) {
		newDefence = 0;
	}
	defence = newDefence;
}

// Sets the damage of the Player
void Player::setDamage(int newDamage) {
	if (newDamage < 0) {
		newDamage = 0;
	}
	damage = newDamage;
}

// Sets the luck of the Player
void Player::setLuck(int newLuck) {
	if (newLuck < 0) {
		newLuck = 0;
	}
	luck = newLuck;
}

// Displays the Player's items in their inventory available to be dropped
void Player::displayInventory() {
	cout << "\n Player Inventory:";
	for (int i = 2; i < inventory.size() - 1; i++) {
		cout << inventory.at(i)->getName() << "[" << i - 2 << "]" << ", ";
	}
	cout << inventory.at(inventory.size() - 1)->getName() << "[" << inventory.size() - 3 << "]" << endl;
}

// Displays the Player's items in their inventory
void Player::displayInventoryItems() {
	if (inventory.empty()) {
		cout << "\n There are no items in the Player's Inventory\n";
	}
	else {
		cout << "\n Player Inventory:";
		for (int i = 0; i < inventory.size() - 1; i++) {
			// Creates a new line for UI purposes
			if (i == 4 or i == 8) {
				cout << endl << " ";
			}
			cout << inventory.at(i)->getName() << ", ";
		}
		cout << inventory.at(inventory.size() - 1)->getName();
	}
}

// Adds an item to the Player's inventory
void Player::addItemToInventory(Item* item) {
	if (inventory.size() < 12) {
		inventory.push_back(item);
	}
	else {
		cout << "Inventory is full! Please remove something before adding more!";
	}
}

// Adds Gold to the Player
void Player::addGold(Gold newGold) {
	int totalGold = gold + newGold;
	gold = Gold(totalGold);
}

// Adds Gem to the Player
void Player::addGem(Gem newGem) {
	int totalGem = gem + newGem;
	gem = Gem(totalGem);
}

// Removes an item to the Player's inventory
Item* Player::removeItemFromInventory(int itemPosition) {
	Item* item = inventory[itemPosition];
	inventory.erase(inventory.begin() + itemPosition);
	return item;
}

// Clears all items from the Player's inventory
void Player::clearInventory() {
	inventory.clear();
}

// Checks if the player has provisions
bool Player::hasProvisions() {
	bool status = false;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getName() == "Provisions") {
			status = true;
		}
	}
	return status;
}

// Checks if the player has all the artefacts
bool Player::hasArtefacts() {
	bool status = false;
	bool item1 = false;
	bool item2 = false;
	bool item3 = false;
	bool item4 = false;
	bool item5 = false;
	// Checks if the individual items are in the inventory
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getName() == "Boots of Speed") {
			item1 = true;
		}
		if (inventory[i]->getName() == "Krangs Battle Axe") {
			item2 = true;
		}
		if (inventory[i]->getName() == "Krangs Chainmail") {
			item3 = true;
		}
		if (inventory[i]->getName() == "Elixir Maxima") {
			item4 = true;
		}
		if (inventory[i]->getName() == "Balthazars Spell Tome") {
			item5 = true;
		}
	}
	if (item1 and item2 and item3 and item4 and item5) {
		status = true;
	}
	return status;
}

// Checks if the player has consumables
bool Player::hasConsumables() {
	bool status = false;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getUses() > 0 and inventory[i]->getName() != "Provisions" and inventory[i]->getName() != "Lantern") {
			status = true;
		}
	}
	return status;
}

// Reduces the Player's health from the hurt damage taken
void Player::hurt(int hurtDamage) {
	hurtDamage -= getDefence();
	if (hurtDamage >= 0) {
		health -= hurtDamage;
	}
	else {
		hurtDamage = 0;
	}
	cout << " You lost " << hurtDamage << "hp" << endl;
}

// Heals the Player's health from the heal amount
void Player::heal(int healAmount) {
	health += healAmount;
	if (health > maxHealth) {
		health = maxHealth;
	}
	cout << " You healed for " << healAmount << " HP" << endl;
}

// Checks if the player is hurt
bool Player::isHurt() {
	if (health < maxHealth) {
		return true;
	}
	return false;
}

// Removes items burnt 
void Player::burnItems() {
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getName() == "Sword" or inventory[i]->getName() == "Leather Armour") {
			cout << " The Dragon burnt your " << inventory[i]->getName() << "!" << endl;
			removeItemFromInventory(i);
		}
	}
}

// Displays the Player's details
void Player::getDetails() {
	cout << "			Player Details            ";
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// access Name Test
	cout << "\n Player Name: " << getName();
	// access Max Health Test
	cout << "\n Player Max Health: " << getMaxHealth();
	// access Health Test
	cout << "\n Player Health: " << getHealth();
	// access Attack Test
	cout << "\n Player Attack: " << getAttack();
	// access Defence Test
	cout << "\n Player Defence: " << getDefence();
	// access Damage Test
	cout << "\n Player Damage: " << getDamage();
	// access Luck Test
	cout << "\n Player Luck: " << getLuck();
	displayInventoryItems();
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

// Tests the Player's constructors and methods
void Player::testPlayer() {
	// Testing default constructor
	getDetails();

	// Testing overloaded constructor and set Name Test
	setName("Bob");
	getDetails();

	// Testing Adding Required Items to Inventory
	addItemToInventory(new Item("Map", ItemType::ITEM, bool("True")));
	addItemToInventory(new Item("Lantern", ItemType::ITEM, 100));
	addItemToInventory(new Item("Provisions", ItemType::ITEM, 4));
	addItemToInventory(new Item("Sword", ItemType::ITEM, bool("True")));
	displayInventory();
}
