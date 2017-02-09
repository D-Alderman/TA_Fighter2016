/*
 * Interfaces.cpp
 * Interfaces will handle all the menus and user interfaces
 * that are seen in the game
 *
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include <iostream>
#include <exception>
#include <limits>
#include "Bosses.h"
#include "Battle.h"
#include "Story.h"

using namespace std;

//validateChoice is constantly used to check user input and make sure it is correct
void validateChoice(int& userChoice) {
	//i looked up a code to handle incorrect input types. i was unable to get
	//error handling to properly function.
	cin.sync();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "I'm sorry, but I did not understand that option. Please enter a number:" << endl;
}

//displayNewMenu displays the new game menu
int displayNewMenu() {
		int userChoice;

		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "*~							 ~*" << endl;
		cout << "*~  1) New Game						 ~*" << endl;
		cout << "*~  2) Exit game					 ~*" << endl;
		cout << "*~							 ~*" << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;

		cout << "Please select a menu option: ";

		while(!(cin>>userChoice)) {
			validateChoice(userChoice);
		}

		if (userChoice < 1 || userChoice > 2) {
			cin.sync();
			cin.clear();
			cout << "I'm sorry, but I did not understand that option. Please select a valid menu option:" << endl;
		}

		return userChoice;
}

//displayMainMenu shows our main fighter select menu
int displayMainMenu(Fighter& chakra, Fighter& islam, Bosses& mishra, Bosses& watney, Bosses& starknight) {
		int userChoice;

		//chakra.setDefeated(true);
		//islam.setDefeated(true);
		//mishra.setDefeated(true);
		//watney.setDefeated(true);

		cout << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
		cout << "*~" << endl;
		cout << "*~  1) Exit" << endl;
		cout << "*~  2) Check Your Fighter Info " << endl;
		cout << "*~  3) Battle Rudrasis Chakraborty" << endl;
		cout << "*~  4) Battle Minhazul Islam" << endl;
		if ((chakra.getDefeated() != false) && (islam.getDefeated() != false)) {
			cout << "*~  5) Challenge Subhankar Mishra" << endl;
		}
		if (mishra.getDefeated() != false ) {
			cout << "*~  6) A New Challenger Arrives" << endl;
		}
		if (watney.getDefeated() != false) {
			cout << "*~  7) The Battle at the Edge of the Universe" << endl;
		}
		cout << "*~" << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;

		cout << "Please select a menu option: ";

		while(!(cin>>userChoice)) {
			validateChoice(userChoice);
		}

		if (userChoice < 1 || userChoice > 7) {
			cin.sync();
			cin.clear();
			cout << "I'm sorry, but I did not understand that option. Please select a valid menu option" << endl;
		}

		return userChoice;
}

//menuHeader shows our title screen
void menuHeader() {

	cout << "******************************************************************************\n";
	cout << "*   _________       _______       __    _                ___   ____ ________ *\n";
	cout << "*  /_  __/   |     / ____(_)___ _/ /_  / /____  _____   |__ \\ / __ <  / ___/ *\n";
	cout << "*   / / / /| |    / /_  / / __ `/ __ \\/ __/ _ \\/ ___/   __/ // / / / / __ \\  *\n";
	cout << "*  / / / ___ |   / __/ / / /_/ / / / / /_/  __/ /      / __// /_/ / / /_/ /  *\n";
	cout << "* /_/ /_/  |_|  /_/   /_/\\__, /_/ /_/\\__/\\___/_/      /____/\\____/_/\\____/   *\n";
	cout << "*                       /____/	 			 		     *\n";
	cout << "*   									     *\n";
	cout << "******************************************************************************" << endl;

}

//menuNavigation uses a switch block to drive our fighter selection. it then calls the battle functions necessary
//to start our battle.
void menuNavigation(int option, Fighter player, Fighter& chakra, Fighter& islam, Fighter& mishra, Bosses& watney, Bosses& starknight) {
	switch (option) {
		case 2: {
			player.printFighterInfo();
			break;
		}
		case 3: {
			chakraIntro();
			chakra.setHealth(140);
			startBattle(player, chakra);
			if (chakra.getDefeated() != false) {
				chakraOutro();
			}
			break;
		}
		case 4: {
			islamIntro();
			islam.setHealth(120);
			startBattle(player, islam);
			if (islam.getDefeated() != false) {
				islamOutro();
			}
			break;
		}
		case 5: {
			mishraIntro();
			mishra.setHealth(200);
			startBattle(player, mishra);
			if (mishra.getDefeated() != false) {
				mishraOutro();
			}
			break;
		}
		case 6: {
			watneyIntro();
			watney.setHealth(230);
			startBattle(player, watney);
			if (watney.getDefeated() != false) {
				watneyOutro();
			}
			break;
		}
		case 7: {
			starknightIntro();
			starknight.setHealth(300);
			startBattle(player, starknight);
			if (starknight.getDefeated() != false) {
				starknightOutro();
			}
			break;
		}
	}
}
