#ifndef BOARD_H
#define	BOARD_H
#include <iostream>
using namespace std;
//typedef int (*Array10x10)[10];
typedef int (&Array10x10)[10][10];
const int water       = 0;
const int ship        = 1;
const int hit         = 2;
const int miss        = 3;
const int alreadyHit  = 4;
const int alreadyMiss = 5;
const int vertical    = 1;
const int horizontal  = 0;

//Ships
const int carrier    = 5;
const int battleship  = 4;
const int crusier    = 3;
const int submarine  = 3;
const int patrol     = 2;

class Board {
public:
    Board();
    //Ship placer
    //@TODO Change int ship to Ship class
    int placeShip(int ship, int x, int y, int direction);
    //Generic Class rig up test
    int nullReturn()  { return 0; };
    //Returns a Reference to the 10x10 set of tiles
    Array10x10 getTiles();
    /**
     * Fires a shot onto the board and returns a value of 2 hit, 3 miss,
     * 4 hit already and 5 miss already
     */
    int fireShot(int x, int y);
    /**
     * Returns an int value of: 2 hit or 3 miss tiles but not
     * listing ship locations.
     * Designed to be looped over for displaying the board to attacker
     */
    int getShots(int x, int y);
    /**
     * Returns an int value of: 0 water, 1 ship, 2 hit or 3 miss tiles.
     * Designed to be looped over for displaying the board to defender
     */
    int getTile(int x, int y);

    int boardPositionToArray(int ship, string input);

    int markShot(string target);

private:
    int tiles[10][10];
};

#endif	/* BOARD_H */

