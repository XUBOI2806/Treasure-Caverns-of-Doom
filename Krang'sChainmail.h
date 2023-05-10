/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: KrangsChainmail Header File
 **************************************************/

#ifndef KRANGSCHAINMAIL_H
#define KRANGSCHAINMAIL_H

 // Add all your #includes, variables and function prototypes here
#include <string>
#include <vector>
#include <iostream>
#include "Armour.h"


using namespace std;

// KrangsChainmail Class
class KrangsChainmail : public Armour {

public:
	// constructor
	KrangsChainmail();
	~KrangsChainmail();
};

#endif
