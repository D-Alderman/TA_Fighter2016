/*
 * Battle.h
 * Header for the Battle.cpp
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#ifndef BATTLE_H_
#define BATTLE_H_

int calculateDamage(Fighter defender, Fighter attacker, Move usedMove);
int battleMenu(Fighter& player, Fighter& enemy, Move playerMoveset[], Move enemyMoveset);
void calculateMoves(Fighter& player, Fighter& enemy, Move playerMove, Move enemyMoveset[], int playerMaxHealth);
void battleMenuNavigation(int choice, Fighter& player, int playerMaxHealth, Move playerMoveset[], Fighter& enemy, Move enemyMoveset[]);
void startBattle(Fighter player, Fighter& enemy);


#endif /* BATTLE_H_ */
