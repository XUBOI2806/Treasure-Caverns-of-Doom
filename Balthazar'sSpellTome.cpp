/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: BalthazarsSpellTome Class Definition File
 **************************************************/

#include "Balthazar'sSpellTome.h"

 // Constructor
BalthazarsSpellTome::BalthazarsSpellTome() {
	name = "Balthazars Spell Tome";
	type = ItemType::ARTEFACT;
	unlimitedUses = bool(1);
}

// Destructor
BalthazarsSpellTome::~BalthazarsSpellTome() {}

