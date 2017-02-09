/*
 * Fighter.h
 * Header for fighter class
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include "Moves.h"

using namespace std;

#ifndef FIGHTER_H_
#define FIGHTER_H_

class Fighter {
protected:
	string fighterName;
	int attack, defense, health;
	Move moveset[5];
	bool isDefeated;
	string fighterInfo;
	int index;

public:
	Fighter();
	Fighter(string name, int atk, int def, int life, string info);
	int getAttack();
	int getDefense();
	int getHealth();
	bool getDefeated();
	string getName();
	void getMoveset(Move movelist[]);
	void setAttack(int newAtk);
	void setDefense(int newDef);
	void setHealth(int newHealth);
	void setDefeated(bool defeated);
	void setMoves(Move move);
	void printFighterInfo();
	void printFighterMoves();
};

#endif /* FIGHTER_H_ */
