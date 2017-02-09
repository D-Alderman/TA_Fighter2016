/*
 * Fighter.cpp
 * Fighter class are the objects that the player
 * and most of the enemies will be. Drives the
 * Bosses subclass as well
 *
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include <iostream>
#include "Fighter.h"

using namespace std;

//default constructor in case something goes wrong!
Fighter::Fighter() {
	fighterName = "";
	attack = 1;
	defense = 1;
	health = 100;
	fighterInfo = "";
	isDefeated = false;
	index = 0;
}

//Fighter constructor initializes this fighter with given statistics
Fighter::Fighter(string name, int atk, int def, int life, string info) {
	this->fighterName = name;
	this->attack = atk;
	this->defense = def;
	this->health = life;
	this->fighterInfo = info;
	this->isDefeated = false;
	this->index = 0;
}

//getAttack returns the fighter's attack value
int Fighter::getAttack() {
	return attack;
}

//getDefense returns the fighter's defense value
int Fighter::getDefense() {
	return defense;
}

//getHealth returns the fighter's health value
int Fighter::getHealth() {
	return health;
}

bool Fighter::getDefeated() {
	return isDefeated;
}

string Fighter::getName() {
	return fighterName;
}

//get moves will get us the fighter's movelist
void Fighter::getMoveset(Move movelist[]) {

	for (int i = 0; i < 5; i++) {
		movelist[i] = moveset[i];
	}
}

//setAttack changes the fighter's attack value
void Fighter::setAttack(int newAtk) {
	this->attack = newAtk;
}

//setDefense changes the fighter's defense value
void Fighter::setDefense(int newDef) {
	this->defense = newDef;
}

//setHealth changes the fighter's health value
void Fighter::setHealth(int newHealth) {
	this->health = newHealth;
}

//setDefeated changes the fighter's deated status
void Fighter::setDefeated(bool defeated) {
	this->isDefeated = defeated;
}

//setMoves instantiates the moves and places them in an array
void Fighter::setMoves(Move move) {
	moveset[index] = move;
	index++;
}

//printFighterInfo will print out information about the fighter
void Fighter::printFighterInfo() {
	cout << "Name: " << fighterName << endl;
	cout << "Health: " << health << "     Attack: " << attack << "     Defense: " << defense << endl;
	cout << fighterInfo << endl << endl;
	printFighterMoves();
}

//prints out the movelist of the fighter
void Fighter::printFighterMoves() {
	for (int i = 0; i < 4; i++) {
		Move move = moveset[i];
		move.printMoveInfo();
	}
}

