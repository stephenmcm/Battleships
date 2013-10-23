/*
 * Opponent.cpp
 *
 *  Created on: 14/10/2013
 *      Author: User
 */

#include "Opponent.h"

namespace battleships {

Opponent::Opponent() {
	// TODO Auto-generated constructor stub

}

Opponent::~Opponent() {
	// TODO Auto-generated destructor stub
}

int Opponent::fireShot(Board &board){
	srand(5323);
	int nHigh = 9;
	int nLow  = 0;
	int attempts = 0; //Safety catch for fireLoop
	while(attempts < 100){
		// Generate a random number between nLow and nHigh (inclusive)
		int posX = (rand() % (nHigh - nLow + 1)) + nLow;
		int posY = (rand() % (nHigh - nLow + 1)) + nLow;
		std::cout << endl << "Firing on X: '"<<posX<<"' Y: '"<<posY<<"'"<<endl;
		switch (board.fireShot(posX,posY))
			{
			  case water:
				  return 0;
				 break;
			  case hit:
				  attempts++;
				 break;
			  case miss:
				  return 0;
				 break;
			  case alreadyHit:
				  attempts++;
				 break;
			  case alreadyMiss:
				  attempts++;
				 break;
			  default:
				  return 0;
			};
	};
	return 0;
};

} /* namespace battleships */
