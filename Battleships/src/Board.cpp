/*
 * Board.cpp
 *
 *  Created on: 24/09/2013
 *      Author: User
 */

#include "board.h"

Board::Board(){
    //set our tiles to 0
    for (int nRow = 0; nRow < 10; nRow++) {
        for (int nCol = 0; nCol < 10; nCol++) {
            this->tiles[nRow][nCol] = 0;
        };
    }
        //return 1;
};

Array10x10 Board::getTiles(){
    return this->tiles;
}

int Board::placeShip(int ship, int x, int y, int direction){

    //out of board check
    if(x > 10 || y > 10){
        return -1;
    }

    //out of board by size check
    if( (direction == 0 && (y + ship) > 10) || (direction == 1 && (x + ship > 10)) )  {
        return -1;
    }

    //test if ships crash
    for(int shipTiles = 0; shipTiles < ship; shipTiles++){
        if( direction == 0 ){
            if(this->tiles[x][y + shipTiles] == 1){
                return -1;
            }
        }else{
            if(this->tiles[x + shipTiles][y] == 1){
                return -1;
            }
        }
    };

    //places ship on board
    for(int shipTiles = 0; shipTiles < ship; shipTiles++){
        if( direction == 0 ){
            this->tiles[x][y + shipTiles] = 1;
        }else{
            this->tiles[x + shipTiles][y] = 1;
        }
    };

    return 0;

}

int Board::fireShot(int x, int y){
    //Hit
    if(this->tiles[x][y] == 1){
        this->tiles[x][y] = 2;
        return 1;
    };
    //Miss
    if(this->tiles[x][y] == 0){
        this->tiles[x][y] = 3;
        return 0;
    };

    //Already Fired on
    //Already Hit
    if(this->tiles[x][y] == 2){
        this->tiles[x][y] = 2;
        return 2;
    };
    //Already Miss
    if(this->tiles[x][y] == 3){
        this->tiles[x][y] = 3;
        return 3;
    };
    //Error
    return -1;

}
