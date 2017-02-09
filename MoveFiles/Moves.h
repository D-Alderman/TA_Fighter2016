/*
 * Moves.h
 * Move header
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include <string>

using namespace std;

#ifndef MOVES_H_
#define MOVES_H_

class Move {
private:
	int movePower;
	string moveName;
	string moveInfo;

public:
	Move();
	Move(int power, string name, string info);
	int getPower();
	string getName();
	void setPower(int newPower);
	void printMoveInfo();
};

#endif /* MOVES_H_ */
