/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: KrangsChainmail Class Definition File
 **************************************************/

#include "Krang'sChainmail.h"

 // Constructor
KrangsChainmail::KrangsChainmail() {
	name = "Krangs Chainmail";
	type = ItemType::ARTEFACT;
	defence = (int)EquipmentDefence::KRANGS_CHAINMAIL;
	unlimitedUses = bool(1);
}

// Destructor
KrangsChainmail::~KrangsChainmail() {}

