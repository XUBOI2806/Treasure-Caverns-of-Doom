/**************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Main header File
 **************************************************/

 // Adding Inclusion Guards
#ifndef MAIN_H
#define MAIN_H

 // Including header file
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "Hobogoblin.h"
#include "Ogre.h"
#include "Troll.h"
#include "Dragon.h"
#include "Item.h"
#include "Map.h"
#include "Location.h"
#include "Gold.h"
#include "Gem.h"
#include "Sword.h"
#include "Provisions.h"
#include "PotionFlask.h"
#include "LeatherArmour.h"
#include "Lantern.h"
#include "Krang'sChainmail.h"
#include "Krang'sBattleAxe.h"
#include "Krang'sChainmail.h"
#include "ElixirMaxima.h"
#include "BootsOfSpeed.h"
#include "Balthazar'sSpellTome.h"

// Add alL #includes, variables and function prototypes here
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

/**************************************************
	TESTING and DEBGGING FUNCTIONS
 **************************************************/
void testPlayer();
void testMonster();
void testGoblin();
void testHobogoblin();
void testDragon();
void testItem();
void testLocation();
void testAll();

/**************************************************
	GAME FUNCTIONS
 **************************************************/
void playGame();
void gameOver(Player* player);
void endGame();
void moveLocation(vector<Location*> locations, int locationNumber, Player* player);
vector<Location*> createMap();
void useLantern(Player* player);

/**************************************************
	SETUP FUNCTIONS
 **************************************************/
Player* createPlayer();
vector<Location*> retrieveLocationsData(string filename);
void initialiseMonsters(vector<Location*> locations);
void initialiseItems(vector<Location*> locations);

/**************************************************
	PLAYER INPUT FUNCTIONS
 **************************************************/
string askForPlayerName();
void waitForPlayer(vector<Location*> locations, int locationNumber);
void askForAction(vector<char> optionList, vector<Location*> locations, int locationNumber);
void runAction(Option option, vector<Location*> locations, int locationNumber, vector<char> optionList);

/**************************************************
	DISPLAY FUNCTIONS
 **************************************************/
vector<char> displayOptions(Location* location);
void displayTextData(string myFile);

#endif
