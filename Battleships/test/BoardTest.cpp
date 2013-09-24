#include "gtest/gtest.h"
#include "Board.h"
#include <iostream>
using namespace std;

TEST(MathTest, TwoPlusTwoEqualsFour) {
  EXPECT_EQ(2 + 2, 4);
}

static  Board testBoard;

TEST(testBoard, DefaultConstructor) {

 EXPECT_EQ(0, testBoard.placeShip(5, 1, 1, 1));

 EXPECT_EQ(0, testBoard.placeShip(5, 8, 1, 0));

}

TEST(testBoard, OutOfBoundsShip) {

 //EXPECT_EQ(-1, testBoard.placeShip(5, 1, 8, 1));

 EXPECT_EQ(-1, testBoard.placeShip(5, 1, 11, 1));

 EXPECT_EQ(-1, testBoard.placeShip(5, 11, 0, 0));

}

TEST(testBoard, OutOfBoundsShipByLength) {

 //EXPECT_EQ(-1, testBoard.placeShip(5, 1, 8, 1));

 EXPECT_EQ(-1, testBoard.placeShip(5, 1, 8, 0));

 EXPECT_EQ(-1, testBoard.placeShip(5, 8, 0, 1));

}

TEST(testBoard, shotFired) {
    //hit
    EXPECT_EQ(1, testBoard.fireShot(1, 1));
    //miss
    EXPECT_EQ(0, testBoard.fireShot(2, 2));
    //miss
    EXPECT_EQ(0, testBoard.fireShot(3, 3));

    //Already fired on
    //hit
    EXPECT_EQ(2, testBoard.fireShot(1, 1));
    //miss
    EXPECT_EQ(3, testBoard.fireShot(2, 2));
}

TEST(testBoard, ShipCrash) {

 EXPECT_EQ(-1, testBoard.placeShip(5, 3, 0, 0));

 Array10x10 tiles = testBoard.getTiles();

for (int nRow = 0; nRow < 10; nRow++){
    for (int nCol = 0; nCol < 10; nCol++){
            cout << tiles[nRow][nCol] << " | ";
    };
    cout << endl;
};
}
