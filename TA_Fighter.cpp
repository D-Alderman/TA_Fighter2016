/*
 * TA_Fighter.cpp
 * Main file that runs  the game
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Instantiate.h"
#include "Bosses.h"
#include "Interfaces.h"
#include "Battle.h"
#include "Story.h"

using namespace std;

int main() {

	//instantiates the players and the bosses
	Fighter playerFighter;
	Fighter rChakra;
	Fighter mIslam;
	Bosses sMishra;
	Bosses mWatney;
	Bosses lStarknight;

	//sets up random variable and the menu choices
	srand(time(0));
	int newMenuChoice = 0;
	int mainMenuChoice = 0;

	//brings up title screen
	menuHeader();

	//while loop for running the game
	while (newMenuChoice != 2) {
		newMenuChoice = displayNewMenu();

		//if player selects new game, instantiates all the characters
		//if player selects exit, break out of the program
		//if player selects anything else, cycle the loop again
		if (newMenuChoice == 1) {
			openingStory();
			mainMenuChoice = 0;
			rChakra = instantiateChakra();
			mIslam = instantiateIslam();
			sMishra = instantiateMishra();
			mWatney = instantiateWatney();
			lStarknight = instantiateStarknight();
			playerFighter = instantiatePlayer();
			instantiatePlayerMoves(playerFighter);
		} else if (newMenuChoice == 2) {
			break;
		}
		else
			continue;

		//inner menu, controlling the fight choices, cycles as long as the player chooses not to exit
		while (mainMenuChoice != 1) {
			mainMenuChoice = displayMainMenu(rChakra, mIslam, sMishra, mWatney, lStarknight);
			menuNavigation(mainMenuChoice, playerFighter, rChakra, mIslam, sMishra, mWatney, lStarknight);
		}
	}

	//when the player chooses to exit the game
	cout << "We await your next challenge!";
}
