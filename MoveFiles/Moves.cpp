/*
 * Moves.cpp
 * Moves drives the creation of the different moves
 * that our fighters use
 *
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include <iostream>
#include <string>
#include "Moves.h"

using namespace std;

//default constructor in case something goes wrong!
Move::Move() {
	movePower = 1;
	moveName = "";
	moveInfo = "";
}

//creates a move with the listed stats
Move::Move(int power, string name, string info) {
	this->movePower = power;
	this->moveName = name;
	this->moveInfo = info;
}

//getPower returns the power
int Move::getPower() {
	return movePower;
}

//getName returns the move name
string Move::getName() {
	return moveName;
}

//setPower changes/updates a moves power
void Move::setPower(int newPower) {
	this->movePower = newPower;
}

//printMoveInfo prints out the information for a move
void Move::printMoveInfo(){
	cout << "Move Name: " << moveName << endl;
	cout << "Power: " << movePower << endl;
	cout << moveInfo << endl << endl;
}
