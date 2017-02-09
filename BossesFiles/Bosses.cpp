/*
 * Bosses.cpp
 *	Bossess are special fighters that have a special ability
 *
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include "Bosses.h"

//constructor sets defaults
Bosses::Bosses() {
	fighterName = "";
	attack = 1;
	defense = 1;
	health = 100;
	fighterInfo = "";
	isDefeated = false;
	index = 0;
}

//creates boss with the made parameters
Bosses::Bosses(string name, int atk, int def, int life, string info) {
	this->fighterName = name;
	this->attack = atk;
	this->defense = def;
	this->health = life;
	this->fighterInfo = info;
}

//setSpecial adds the special move into the last moveset array index
void Bosses::setSpecial(Move move) {
	moveset[4] = move;
}
