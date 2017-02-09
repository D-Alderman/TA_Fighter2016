/*
 * Bosses.h
 * Header for Bosses subclass
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include "Fighter.h"

#ifndef BOSSES_H_
#define BOSSES_H_

class Bosses : public Fighter {
protected:
	Move specialMove;

public:
	Bosses();
	Bosses(string name, int atk, int def, int life, string info);
	void setSpecial(Move move);
};

#endif /* BOSSES_H_ */
