/*
 * Interfaces.h
 * Interface header
 *
 *  Created on: Jul 19, 2016
 *      Author: celxius
 */

#ifndef INTERFACES_H_
#define INTERFACES_H_

int displayNewMenu();
int displayMainMenu(Fighter& chakra, Fighter& islam, Bosses& mishra, Bosses& watney, Bosses& starknight);
void validateChoice(int& userChoice);
void menuHeader();
void menuNavigation(int option, Fighter player, Fighter& chakra, Fighter& islam, Fighter& mishra, Bosses& watney, Bosses& starknight);

#endif /* INTERFACES_H_ */

