/*
 * Instantiate.cpp
 * Handles all the fighter, boss and player creation
 * Each can be easily edited or customized
 *
 *  Created on: Jul 20, 2016
 *      Author: celxius
 */

#include "Bosses.h"
#include "Interfaces.h"
#include "Instantiate.h"
#include <iostream>

using namespace std;

//instatiatePlayer handles the player creation menu
//takes in player choices and creates the player Fighter object
Fighter instantiatePlayer() {
	string playerName;
	int playerAtk, playerDef, playerLife;
	int totalPlayerAtk, totalPlayerDef, totalPlayerLife;

	cout << endl;
	cout << "Please enter your player name: ";
	cin >> playerName;

	cout << endl;
	cout << "You will now get the chance to customize your fighter's attack, defense and health stats" << endl;
	cout << "The total value of these three stats cannot exceed 15 points." << endl;

	do {

		cout << endl;
		cout << "Please enter your player attack power: ";

		while(!(cin>>playerAtk)) {
			validateChoice(playerAtk);
		}

		cout << "Please enter your player defense power: ";
		while(!(cin>>playerDef)) {
			validateChoice(playerDef);
		}

		cout << "Please enter your player health: ";
		while(!(cin>>playerLife)) {
			validateChoice(playerLife);
		}

		if ((playerAtk + playerDef + playerLife) > 15) {
			cout << "I'm sorry, but the total value of your attack, defense, and health cannot be more than 15." << endl;
			cout << "Please enter new values." << endl;
		}

	} while((playerAtk + playerDef + playerLife) > 15);

	totalPlayerAtk = (playerAtk + 10);
	totalPlayerDef = (playerDef + 10);
	totalPlayerLife = (playerLife * 20);

	Fighter playerFighter = Fighter(playerName, totalPlayerAtk, totalPlayerDef, totalPlayerLife, "This student has risen above all the rest, "
			"and is now challenging the strongest TAs for the top spot");

	return playerFighter;
}

//instantiateChakra creates our TA Chakra
Fighter instantiateChakra() {

	//creates the fighter, the moves and places them into the move array
	Move javaThrow(12, "Java Throw", "Uses the opponents knowledge of Java against them.");
	Move vectorCrush(17, "Vector Crush", "Attacks the opponent with an ever growing arsenal of blows");
	Move catchExceptions(0, "Catch All Exceptions", "The user focuses on eliminating any errors and blocks the opponents next attack.");
	Move constantPain(28, "Constant Pain", "The user points to a pointer to a pointer to another pointer, "
			"giving the opponent a massive headache.");

	Fighter rChakra("Rudrasis Chakraborty", 11, 15, 140,
			"This TA gets up and teaches the early classes. He then spends all afternoon training in the art "
			"of JavaJitsu.");
	rChakra.setMoves(javaThrow);
	rChakra.setMoves(vectorCrush);
	rChakra.setMoves(catchExceptions);
	rChakra.setMoves(constantPain);

	return rChakra;
}

//instantiateIslam creates our TA Islam
Fighter instantiateIslam() {

	//creates the fighter, the moves and places them into the move array
	Move functionRecall(13, "Function Recall", "The user focuses, and then proceeds to strike at weak points in the target.");
	Move exceptionThrow(15, "Exception Throw", "Attacks the opponent without any errors in the strikes!");
	Move eclipse(21, "Eclipse", "The user uses the power of the shadow of the moon to hide a deadly strike.");
	Move arrayOfPain(30, "Array of Pain", "The user gathers all his power in order to launch a massive attack on his opponent.");

	Fighter mIslam("Minhazul Islam", 16, 12, 110,
			"This TA hones his skills under the cover of dusk before teaching the night classes. He is known for his fierce attacks.");
	mIslam.setMoves(functionRecall);
	mIslam.setMoves(exceptionThrow);
	mIslam.setMoves(eclipse);
	mIslam.setMoves(arrayOfPain);

	return mIslam;
}

//instantiateMishra creates our Professor Mishra
Bosses instantiateMishra() {

	//creates the fighter, the moves and places them into the move array
	Move classInSession(13, "Class is in Session", "Subhankar welcomes the new TA into the class, with an epic beatdown.");
	Move runTimeError(17, "Run Time Error", "Subhankar waits menancingly for the TA to make a mistake, and then capitalizes on the"
			" opportunity.");
	Move magicSquare(2, "Magic Square", "The target is blocked and attacked by a random odd number of blows");
	Move voidRush(21, "Void Rush", "Subhankar moves at lightning spead to deliver a powerful attack.");
	Move virtualOverload(29, "Virtual Overload", "Subhankar harnesses the power from all the TAs he has defeated over the years, "
			"and releases an ultra-powerful attack.");

	Bosses sMishra("Subhankar Mishra", 18, 16, 200,
				"His mastery of languages is unparalleled. It is said that he knows the secrets to dividing by zero without \n"
				"throwing an exception.");
	sMishra.setMoves(classInSession);
	sMishra.setMoves(runTimeError);
	sMishra.setMoves(magicSquare);
	sMishra.setMoves(voidRush);
	sMishra.setSpecial(virtualOverload);

	return sMishra;
}

//instantiateWatney creates our secret boss Watney
Bosses instantiateWatney() {
	Move lawOfCosines(17, "Law of Cosines", "The Challenger uses perfected logical equations to calculate enemy weakpoints.");
	Move hubSmash(18, "Hub Smash", "Using a piece of his downed space ship, the Challenger swings furiously at his opponent");
	Move hexadecimalFury(16, "Hexadecimal Fury", "The Challenger fires 16 shots from his space blaster at his enemy");
	Move lewisRescue(10, "Lewis to the Rescue", "The Challenger calls on the aid of a friend to assist him, and keep his enemies at bay");
	Move martianRevenge(31, "Martian Revenge", "The Challenger jumps in his space ship and uses it to ram his enemies");

	Bosses mWatney("Astronaut Mark Watney", 20, 19, 230,
			"This man has survived through remarkable ordeals, and braved the depths of space in order to seek revenge"
			" on the Spring 2016 COP 3502 class.");

	mWatney.setMoves(lawOfCosines);
	mWatney.setMoves(hubSmash);
	mWatney.setMoves(hexadecimalFury);
	mWatney.setMoves(lewisRescue);
	mWatney.setSpecial(martianRevenge);

	return mWatney;
}

//instantiateStarknight creates our special boss Starknight
Bosses instantiateStarknight() {
	Move pushAndPop(18, "Push and Pop", "The Traveler carefully places records on top of a stack, before dropping them on the enemy");
	Move celestialDance(0, "Celestial Dance", "The Traveler performs a mesmerizing dance, stunning her opponent and increasing her attack and defense");
	Move starlight(19, "Starlight", "A beam of light shines out from the Traveler's record scanning device and damages the enemy");
	Move grandFinale(21, "Grand Finale", "The Traveler calls on some friends to host an intergalactic concert on your head");
	Move planataryImplosion(34, "Planatary Implosion", "After finding all the records in a location, the Traveler will set charges to"
			" explode the planet.");

	Bosses lStarknight("Lucy Starknight", 23, 22, 300, "This woman has traveled through the far reaches in space, in search for the "
			"rarest records in universe.");

	lStarknight.setMoves(pushAndPop);
	lStarknight.setMoves(celestialDance);
	lStarknight.setMoves(starlight);
	lStarknight.setMoves(grandFinale);
	lStarknight.setSpecial(planataryImplosion);

	return lStarknight;
}

//moveConfirmation drives the confirmation of player selected moves
bool moveConfirmation(Fighter& player, Move& move) {
	int choice;

	move.printMoveInfo();
	cout << "Do you want to add " << move.getName() << " to your movelist?" << endl;
	cout << "1 for yes, 2 for no" << endl;
	cin >> choice;

	if (choice == 1) {
		player.setMoves(move);
		return true;
	} else if (choice == 2) {
		return false;
	} else
		return false;
}

//instantiatePlayerMoves allows the player to select moves from a list to
//add to his moveset. The player cannot add more than 4 moves
void instantiatePlayerMoves(Fighter& player) {

	Move javaThrow(15, "Java Throw", "Uses the opponents knowledge of Java against them.");
	Move binaryBeatdown(11, "Binary Beatdown", "Attacks the opponent with a single powerful blow, twice!");
	Move readSyllabus(0, "Read the Syllabus", "The user reads the syllbus, increasing their defense through sheer knowledge.");
	Move allNighter(0, "Pull All Nighter", "The user stays up all night punching a wall in frustration, increasing their attack power.");
	Move pairCoding(20, "Paired Coding", "The user teams up with a classmate to attack the opponent");
	Move shotOfEspresso(0, "Shot of Espresso", "The user takes a full shot of espresso, healing their lost health");

	int k = 4;
	bool moveAdded;

	for (int i = 0; i < 4; i++) {
		int userMoveChoice = 0;

		cout << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "*~" << endl;
		cout << "*~  1) Java Throw" << endl;
		cout << "*~  2) Binary Beatdown" << endl;
		cout << "*~  3) Read the Syllabus" << endl;
		cout << "*~  4) Pull All Nighter" << endl;
		cout << "*~  5) Paired Coding" << endl;
		cout << "*~  6) Shot of Espresso" << endl;
		cout << "*~" << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;

		cout << "Choose " << k << " more moves for your character!" << endl;

		while(!(cin>>userMoveChoice)) {
			validateChoice(userMoveChoice);
		}

		switch (userMoveChoice) {
			case 1: {
				moveAdded = moveConfirmation(player, javaThrow);
				break;
			}
			case 2: {
				moveAdded = moveConfirmation(player, binaryBeatdown);
				break;
			}
			case 3: {
				moveAdded = moveConfirmation(player, readSyllabus);
				break;
			}
			case 4: {
				moveAdded = moveConfirmation(player, allNighter);
				break;
			}
			case 5: {
				moveAdded = moveConfirmation(player, pairCoding);
				break;
			}
			case 6: {
				moveAdded = moveConfirmation(player, shotOfEspresso);
			}
		}

		//if the player chose not to add the move, the loop continues on
		//and they do not lose a spot
		if (moveAdded == false) {
			i--;
			k++;
		}

		k--;
	}
}
