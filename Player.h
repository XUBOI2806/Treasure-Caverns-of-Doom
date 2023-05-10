/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Player Header File
 **************************************************/

#ifndef PLAYER_H
#define PLAYER_H

 // All #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Gold.h"
#include "Gem.h"
#include "Monster.h"
#include "Weapon.h"
#include "Armour.h"
#include "Lantern.h"
#include "Map.h"
#include "Sword.h"

using namespace std;

// Player Class
class Player {

private:
	string name;
	int maxHealth;
	int health;
	int attack;
	int defence;
	int damage;
	int luck;
	vector<Item*> inventory;
	Gold gold;
	Gem gem;

public:
	// constructor
	Player();
	Player(string name);
	~Player();

	// accessor methods
	string getName();
	int getMaxHealth();
	int getHealth();
	bool isAlive();
	int getAttack();
	int getDefence();
	int getDamage();
	int getLuck();
	vector<Item*> getInventory();
	void getGold();
	void getGems();

	// mutator methods
	void setName(string newName);
	void setMaxHealth(int newMaxHealth);
	void setHealth(int newHealth);
	void setAttack(int newAttack);
	void setDefence(int newDefence);
	void setDamage(int newDamage);
	void setLuck(int newLuck);


	// methods
	void heal(int healAmount);
	void hurt(int hurtDamage);
	bool isHurt();
	void displayInventory();
	void displayInventoryItems();
	void addItemToInventory(Item* item);
	void clearInventory();
	bool hasProvisions();
	bool hasConsumables();
	bool hasArtefacts();
	Item* removeItemFromInventory(int itemPosition);
	void addGold(Gold gold);
	void addGem(Gem gem);
	void burnItems();
	void getDetails();
	void testPlayer();

};

#endif