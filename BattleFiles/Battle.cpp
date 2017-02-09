/*
 * Battle.cpp
 * Controls the battle function in the game
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#include "Bosses.h"
#include "Moves.h"
#include "Story.h"
#include "Interfaces.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//calculateDamage will take the defender's def, the attacker's attack and the move power
//to calculate total damage. There are also three random ints to create variance
int calculateDamage(Fighter defender, Fighter attacker, Move usedMove) {

	int randomMovePower = rand() % 7- 3;
	int randomAttackPower = rand() % 7 - 3;
	int randomDefensePower = rand() % 7 -3;

	int movePower = usedMove.getPower();
	int attackerAtk = attacker.getAttack();
	int defenderDef = defender.getDefense();

	cout << attacker.getName() << " used " << usedMove.getName() << "!" << endl;

	int damageTaken = ((movePower + randomMovePower) + (attackerAtk + randomAttackPower) - (defenderDef + randomDefensePower));

	if (damageTaken <= 0) {
		return 0;
	} else
		return damageTaken;
}

//battleMenu drives the menu of the fights, giving the player the option to pick a move
int battleMenu(Fighter player, Fighter enemy, Move playerMoveset[]) {

	int userBattleChoice;

	cout << endl;
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
	cout << "*~	Your Health: " << player.getHealth() << "	Enemy Health: " << enemy.getHealth() << endl;
	cout << "*~							 " << endl;
	cout << "*~  1) Use " << playerMoveset[0].getName() << endl;
	cout << "*~  2) Use " << playerMoveset[1].getName() << endl;
	cout << "*~  3) Use " << playerMoveset[2].getName() << endl;
	cout << "*~  4) Use " << playerMoveset[3].getName() << endl;
	cout << "*~  5) Examine Opponent	" << endl;
	cout << "*~  6) Check Your Fighter Info	" << endl;
	cout << "*~							 " << endl;
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;

	while(!(cin>>userBattleChoice)) {
		validateChoice(userBattleChoice);
	}

	if (userBattleChoice < 1 || userBattleChoice > 6) {
		cin.sync();
		cin.clear();
		cout << "I'm sorry, but I did not understand that option. Please select a valid menu option" << endl;
	}

	return userBattleChoice;
}

//calculateMoves drives the special move conditions and selects an enemy move to be used
void calculateMoves(Fighter& player, Fighter& enemy, Move playerMove, Move enemyMoveset[], int playerMaxHealth) {
	string playerMoveName = playerMove.getName();
	string enemyName = enemy.getName();
	string enemyMoveName;
	Move enemyMove;

	int randomEnemyMove = rand() % 100 + 1;

	if (enemyName == "Rudrasis Chakraborty" || enemyName == "Minhazul Islam") {
		if (randomEnemyMove >= 1 && randomEnemyMove <= 60) {
			enemyMove = enemyMoveset[0];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 61 && randomEnemyMove <= 75) {
			enemyMove = enemyMoveset[1];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 76 && randomEnemyMove <= 90) {
			enemyMove = enemyMoveset[2];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 91 && randomEnemyMove <= 100) {
			enemyMove = enemyMoveset[3];
			enemyMoveName = enemyMove.getName();
		}
	} else if (enemyName == "Subhankar Mishra" || enemyName == "Astronaut Mark Watney" || enemyName == "Lucy Starknight") {
		if (randomEnemyMove >= 1 && randomEnemyMove <= 40) {
			enemyMove = enemyMoveset[0];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 41 && randomEnemyMove <= 60) {
			enemyMove = enemyMoveset[1];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 61 && randomEnemyMove <= 75) {
			enemyMove = enemyMoveset[2];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 76 && randomEnemyMove <= 90) {
			enemyMove = enemyMoveset[3];
			enemyMoveName = enemyMove.getName();
		} else if (randomEnemyMove >= 91 && randomEnemyMove <= 100) {
			enemyMove = enemyMoveset[4];
			enemyMoveName = enemyMove.getName();
		}
	}

	int playerAtk = player.getAttack();
	int playerDef = player.getDefense();
	int playerHealth = player.getHealth();
	int enemyHealth = enemy.getHealth();

	//if block for certain boss special move conditions
	if(enemyMoveName == "Magic Square") {

		int numAtks = rand() % 7 + 3;

		while (numAtks % 2 == 0) {
			numAtks = rand() % 7 + 3;
		}

		int damage = calculateDamage(player, enemy, enemyMove);
		int playerDamageTaken = damage * numAtks;
		cout << "A magical barrier is created, and blocks your attack." << endl;
		cout << "Magic Square hit " << numAtks << " times!" << endl;
		cout << "You take " << playerDamageTaken << " points of damage." << endl;
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
				return;
			} else {
				player.setHealth(playerNewHealth);
				playerHealth = player.getHealth();
				return;
			}
	} else if (enemyMoveName == "Lewis to the Rescue") {

		int playerDamageTaken = calculateDamage(player, enemy, enemyMove);

		cout << enemy.getName() << "'s friend gives him a small barrier, and fires a quick blaster shot." << endl;
		cout << "You take " << playerDamageTaken << " points of damage and " << endl;
		cout << enemy.getName() << " gains a 10 health barrier" << endl << endl;
		enemy.setHealth(enemyHealth + 10);
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}
	} else if (enemyMoveName == "Push and Pop") {

		int numAtks = rand() % 5 + 1;

		int damage = calculateDamage(player, enemy, enemyMove);
		int playerDamageTaken = damage;
		cout << enemyName << " added " << numAtks << " records to the stack." << endl;
		cout << "She rushes to add one more, but falls into the stack instead. " << endl;
		cout << "You take " << playerDamageTaken << " points of damage." << endl << endl;
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}
	}


	//if block for player move conditions
	if (enemyMoveName == "Catch All Exceptions") {
		cout << enemy.getName() << " used " << enemyMoveName << "!" << endl;
		cout << "He blocked your attack this turn!" << endl;
		return;
	}  else if (enemyMoveName == "Celestial Dance") {
		cout << enemyName << " used " << enemyMoveName << "!" << endl;
		cout << enemyName << " twirls and delivers a cosmic dance." << endl;
		cout << "Her attack goes up!" << endl;
		cout << "Her defense goes up!" << endl << endl;
		int tempAtk = enemy.getAttack();
		int tempDef = enemy.getDefense();
		enemy.setAttack(tempAtk + 1);
		enemy.setDefense(tempDef + 1);
	} else if (playerMoveName == "Read the Syllabus") {
		cout << player.getName() << " used " << playerMoveName << "!" << endl;
		cout << "\nYou read throught the listen on TA battles in the syllabus." << endl;
		cout << "Your defense goes up!" << endl << endl;
		int temp = (playerDef + 3);
		player.setDefense(temp);

		int playerDamageTaken = calculateDamage(player, enemy, enemyMove);
		cout << "You take " << playerDamageTaken << " points of damage." << endl;
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}

	} else if (playerMoveName == "Pull All Nighter") {
		cout << player.getName() << " used " << playerMoveName << "!" << endl;
		cout << "\nYou spend the night trying to understand pointers to pointers to pointers to pointers." << endl;
		cout << "Your attack goes up!" << endl << endl;
		int temp = (playerAtk + 3);
		player.setAttack(temp);

		int playerDamageTaken = calculateDamage(player, enemy, enemyMove);
		cout << "You take " << playerDamageTaken << " points of damage." << endl << endl;
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}

	} else if (playerMoveName == "Shot of Espresso") {
		cout << player.getName() << " used " << playerMoveName << "!" << endl;
		cout << "\nYou drink a piping hot cup of espresso." << endl;
		cout << "You feel revitalized!" << endl;

		int temp = (rand() % 15 + 16);
		int newHealth = (playerHealth + temp);
		if (newHealth >= playerMaxHealth) {
			player.setHealth(playerMaxHealth);
			cout << "You're back at full health!" << endl << endl;
		} else {
			player.setHealth(newHealth);
			cout << "You regain " << temp << " health." << endl << endl;
		}

		int playerDamageTaken = calculateDamage(player, enemy, enemyMove);
		cout << "You take " << playerDamageTaken << " points of damage." << endl;
		int playerNewHealth = (player.getHealth() - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}

	} else if (playerMoveName == "Binary Beatdown"){
		cout << "First Hit!" << endl;
		int enemyDamageTaken1 = calculateDamage(enemy, player, playerMove);
		cout << enemy.getName() << " takes " << enemyDamageTaken1 << " points of damage." << endl << endl;
		cout << "Second Hit!" << endl;
		int enemyDamageTaken2 = calculateDamage(enemy, player, playerMove);
		cout << enemy.getName() << " takes " << enemyDamageTaken2 << " points of damage." << endl << endl;

		int enemyNewHealth = (enemyHealth - (enemyDamageTaken1 + enemyDamageTaken2));
		if (enemyNewHealth <= 0 ) {
			cout << "You have deafeated " << enemy.getName() << "!" << endl;
			enemy.setHealth(enemyNewHealth);
			return;
		} else {
			enemy.setHealth(enemyNewHealth);
		}

		int playerDamageTaken = calculateDamage(player, enemy, enemyMove);
		cout << "You take " << playerDamageTaken << " points of damage." << endl << endl;
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}

	} else {
		int enemyDamageTaken = calculateDamage(enemy, player, playerMove);
		cout << enemy.getName() << " takes " << enemyDamageTaken << " points of damage." << endl << endl;
		int enemyNewHealth = (enemyHealth - enemyDamageTaken);
		if (enemyNewHealth <= 0 ) {
			cout << "You have deafeated " << enemy.getName() << "!" << endl;
			enemy.setHealth(enemyNewHealth);
			return;
		} else {
			enemy.setHealth(enemyNewHealth);
		}

		int playerDamageTaken = calculateDamage(player, enemy, enemyMove);
		cout << "You take " << playerDamageTaken << " points of damage." << endl << endl;
		int playerNewHealth = (playerHealth - playerDamageTaken);
		if (playerNewHealth <= 0) {
			cout << "You have been defeated..." << endl;
			cout << "Please try again " << endl;
			player.setHealth(playerNewHealth);
			return;
		} else {
			player.setHealth(playerNewHealth);
		}
	}
}

//battleMenuNavigation drives the move choice set by the player.
void battleMenuNavigation(int choice, Fighter& player, int playerMaxHealth, Move playerMoveset[], Fighter& enemy, Move enemyMoveset[]) {
	switch(choice) {
		case 1: {
			calculateMoves(player, enemy, playerMoveset[0], enemyMoveset, playerMaxHealth);
			break;
		}
		case 2: {
			calculateMoves(player, enemy, playerMoveset[1], enemyMoveset, playerMaxHealth);
			break;
		}
		case 3: {
			calculateMoves(player, enemy, playerMoveset[2], enemyMoveset, playerMaxHealth);
			break;
		}
		case 4: {
			calculateMoves(player, enemy, playerMoveset[3], enemyMoveset, playerMaxHealth);
			break;
		}
		case 5: {
			enemy.printFighterInfo();
			break;
		}
		case 6: {
			player.printFighterInfo();
			break;
		}
	}
}

//starts up the battle by taking the player object and the selected enemy.
//while loop keeps the battle going until someone reaches 0 health
void startBattle(Fighter player, Fighter& enemy) {

	int battleChoice = 0;
	int playerMaxHealth = player.getHealth();
	int playerHealth = player.getHealth();
	int enemyHealth = enemy.getHealth();
	Move playermoves[5];
	player.getMoveset(playermoves);
	Move enemymoves[5];
	enemy.getMoveset(enemymoves);

	while ((playerHealth > 0) && (enemyHealth > 0)) {
		battleChoice = battleMenu(player, enemy, playermoves);
		battleMenuNavigation(battleChoice, player, playerMaxHealth, playermoves, enemy, enemymoves);
		playerHealth = player.getHealth();
		enemyHealth = enemy.getHealth();

		if (enemyHealth <= 0) {
			enemy.setDefeated(true);
		}
	}
}
