#ifndef BOARD_H
#define	BOARD_H
//typedef int (*Array10x10)[10];
typedef int (&Array10x10)[10][10];

class Board {
public:
    Board();
    int placeShip(int ship, int x, int y, int direction);
    int nullReturn()  { return 0; };
    Array10x10 getTiles();
    int fireShot(int x, int y);
private:
    int tiles[10][10];

};

#endif	/* BOARD_H */

