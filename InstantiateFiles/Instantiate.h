/*
 * Instantiate.h
 * Instantiate header
 *
 *  Created on: Jul 20, 2016
 *      Author: celxius
 */

#include "Bosses.h"

#ifndef INSTANTIATE_H_
#define INSTANTIATE_H_

Fighter instantiatePlayer();
Fighter instantiateChakra();
Fighter instantiateIslam();
Bosses instantiateMishra();
Bosses instantiateWatney();
Bosses instantiateStarknight();
bool moveConfirmation(Fighter& player, Move& move);
void instantiatePlayerMoves(Fighter& player);

#endif /* INSTANTIATE_H_ */
