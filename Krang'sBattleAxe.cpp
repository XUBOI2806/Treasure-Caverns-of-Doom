/*************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: KrangsBattleAxe Class Definition File
 **************************************************/

#include "Krang'sBattleAxe.h"

 // Constructor
KrangsBattleAxe::KrangsBattleAxe() {
	name = "Krangs Battle Axe";
	type = ItemType::ARTEFACT;
	damage = (int)WeaponDamage::KRANGS_BATTLE_AXE;
	unlimitedUses = bool(1);
}

// Destructor
KrangsBattleAxe::~KrangsBattleAxe() {}

