/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Monster Header File
 **************************************************/

#ifndef MONSTER_H
#define MONSTER_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

// Monster Class
class Monster {

protected:
	string name;
	int level;
	int health;
	int attack;
	int defence;
	int damage;
	int dropPercent;
	vector<Item*> drops;

public:
	// constructor
	Monster();
	Monster(string inputName, int inputLevel, vector<Item*> newDrops, int inputItemDropPercent);
	~Monster();

	// accessor methods
	virtual string getName();
	virtual int getLevel();
	virtual int getHealth();
	virtual bool isAlive();
	virtual int getAttack();
	virtual int getDefence();
	virtual int getDamage();
	virtual int getItemDropPercent();
	virtual vector<Item*> getDrops();
	virtual void displayDrops();

	// mutator methods
	virtual void setMonsterName(string newName);
	virtual void setMonsterLevel(int newLevel);
	virtual void setDamage(int newDamage);
	virtual void setDrops(vector<Item*> newDrops);
	virtual void setDropPercent(int newItemDropPercent);

	// methods
	virtual void hurt(int hurtDamage);
	virtual void getDetails();
	virtual void testMonster();
};

#endif
