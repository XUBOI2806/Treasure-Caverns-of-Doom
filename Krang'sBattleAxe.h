/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: KrangsBattleAxe Header File
 **************************************************/

#ifndef KRANGSBATTLEAXE_H
#define KRANGSBATTLEAXE_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Weapon.h"


using namespace std;

// KrangsBattleAxe Class
class KrangsBattleAxe : public Weapon {

public:
	// constructor
	KrangsBattleAxe();
	~KrangsBattleAxe();
};

#endif
