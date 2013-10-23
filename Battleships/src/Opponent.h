/*
 * Opponent.h
 *
 *  Created on: 14/10/2013
 *      Author: User
 */

#ifndef OPPONENT_H_
#define OPPONENT_H_
#include "board.h"
namespace battleships {

class Opponent {
public:
	Opponent();
	virtual ~Opponent();
	void placeShips(Board board);
	int fireShot(Board &board);
};

} /* namespace battleships */
#endif /* OPPONENT_H_ */
