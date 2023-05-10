/**************************************************
  Project: Treasure Caverns of Doom
  Assignment Num: Assignment 4
  Author: Felix Xu
  Purpose: Enums File
 **************************************************/

#ifndef ENUMS_H
#define ENUMS_H
enum class ItemType {
	ARTEFACT,
	POTION,
	WEAPON,
	ARMOUR,
	ITEM
};

enum class WeaponDamage {
	SWORD = 2,
	KRANGS_BATTLE_AXE = 8,
};

enum class EquipmentDefence {
	LEATHER_ARMOUR = 4,
	KRANGS_CHAINMAIL = 12,
	BOOTS_OF_SPEED = 6
};

enum class Option {
	Q = 'Q',
	H = 'H',
	M = 'M',
	T = 'T',
	D = 'D',
	P = 'P',
	N = 'N',
	S = 'S',
	E = 'E',
	W = 'W',
	F = 'F',
	A = 'A',
	X = 'X',
	C = 'C'
};

#endif