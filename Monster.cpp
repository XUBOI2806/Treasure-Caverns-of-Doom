/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Monster Class Definition File
 **************************************************/

#include "Monster.h"

 // Constructor
Monster::Monster() {
	name = "";
	level = 0;
	health = 0;
	attack = 0;
	defence = 0;
	damage = 0;
	drops;
	dropPercent = 0;
}

// Overloading Constructor
Monster::Monster(string inputName, int inputLevel, vector<Item*> newDrops, int inputItemDropPercent) {
	setMonsterName(inputName);
	setMonsterLevel(inputLevel);
	health = 0;
	attack = 0;
	defence = 0;
	damage = 0;
	setDrops(newDrops);
	setDropPercent(inputItemDropPercent);
}

// Destructor
Monster::~Monster() {
	for (int i = 0; i < drops.size() - 1; i++) {
		delete drops[i];
	}
}

// Retrieves the name of the Monster
string Monster::getName() {
	return name;
}

// Retrieves the level of the Monster
int Monster::getLevel() {
	return level;
}

// Retrieves the health of the Monster
int Monster::getHealth() {
	return health;
}

// Retrieves the name of the Monster
bool Monster::isAlive() {
	return health > 0;
}

// Retrieves the attack of the Monster
int Monster::getAttack() {
	return attack;
}

// Retrieves the defence of the Monster
int Monster::getDefence() {
	return defence;
}

// Retrieves the damage of the Monster
int Monster::getDamage() {
	return damage;
}

// Retrieves the item drop percent of the Monster
int Monster::getItemDropPercent() {
	return dropPercent;
}

// Retrieves the inventory of the Monster
vector<Item*> Monster::getDrops() {
	return drops;
}

// Reduces the Monster's health from the hurt damage taken
void Monster::hurt(int hurtDamage) {
	hurtDamage -= getDefence();
	if (hurtDamage >= 0) {
		health -= hurtDamage;
	}
	else {
		hurtDamage = 0;
	}
	cout << " You inflicted " << hurtDamage << " dmg" << endl;
}

// Sets the Monster's name
void Monster::setMonsterName(string newName) {
	if (newName.length() > 0) {
		name = newName;
	}
	else {
		name = "Monster";
	}
}

// Sets the Monster's level
void Monster::setMonsterLevel(int newLevel) {
	if (newLevel > 0) {
		level = newLevel;
	}
	else {
		level = 1;
	}
}

// Sets the Monster's name
void Monster::setDamage(int newDamage) {
	damage = newDamage;
}

// Sets the Monster' of the Location's drops
void Monster::setDrops(vector<Item*> newDrops) {
	drops = newDrops;
}

// Sets the Monster's drop percent
void Monster::setDropPercent(int newDropPercent) {
	if (newDropPercent >= 0 && newDropPercent <= 100) {
		dropPercent = newDropPercent;
	}
	else {
		dropPercent = 100;
	}
}

// gets the Monster's details
void Monster::getDetails() {
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// access Name Test
	cout << "\n Monster Name: " << getName();
	// access Score Test
	cout << "\n Monster Health: " << getHealth();
	cout << "\n Monster Level: " << getLevel();
	cout << "\n Monster Attack: " << getAttack();
	cout << "\n Monster Defence: " << getDefence();
	cout << "\n Monster Damage: " << getDamage();
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

// Returns the items in the monster
void Monster::displayDrops() {
	int rng = rand() % 101;
	if (rng > dropPercent) {
		drops.clear();
	}
	if (drops.empty()) {
		cout << " The Monster dropped no items!" << endl;
	}
	else {
		cout << " The Monster dropped: ";
		for (int i = 0; i < drops.size() - 1; i++) {
			cout << drops.at(i)->getName() << ", ";
		}
		cout << drops.at(drops.size() - 1)->getName() << endl;
	}
}

// Monster test
void Monster::testMonster() {
	getDetails();

	vector<Item*> newDrops;
	newDrops.push_back(new Item("Armour", ItemType::ARMOUR, bool("True")));
	newDrops.push_back(new Item("Provisions", ItemType::ITEM, 4));

	setDrops(newDrops);
	getDetails();
}
