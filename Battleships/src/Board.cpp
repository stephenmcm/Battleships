/*
 * Board.cpp
 *
 *  Created on: 24/09/2013
 *      Author: User
 */

#include "board.h"
#include <iostream>
using namespace std;

Board::Board(){
    //set our tiles to 0
    for (int nRow = 0; nRow < 10; nRow++) {
        for (int nCol = 0; nCol < 10; nCol++) {
            this->tiles[nRow][nCol] = 0;
        };
    }
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
    if( (direction == vertical && (y + ship) > 10) || (direction == horizontal && (x + ship > 10)) )  {
        return -1;
    }

    //test if ships crash
    for(int shipTiles = 0; shipTiles < ship; shipTiles++){
        if( direction == vertical ){
            if(this->tiles[x][y + shipTiles] == 1){
                return -1;
            }
        }else{ //else we're horizontal
            if(this->tiles[x + shipTiles][y] == 1){
                return -1;
            }
        }
    };

    //places ship on board
    for(int shipTiles = 0; shipTiles < ship; shipTiles++){
        if( direction == vertical ){
            this->tiles[x][y + shipTiles] = 1;
        }else{ // horizontal
            this->tiles[x + shipTiles][y] = 1;
        }
    };

    return 0;

}

int Board::fireShot(int x, int y){
    //Hit
    if(this->tiles[x][y] == ship){
        this->tiles[x][y] = hit;
        return hit;
    };
    //Miss
    if(this->tiles[x][y] == water){
        this->tiles[x][y] = miss;
        return miss;
    };

    //Already Fired on
    //Already Hit
    if(this->tiles[x][y] == hit){
        return alreadyHit;
    };
    //Already Miss
    if(this->tiles[x][y] == miss){
        return alreadyMiss;
    };
    //Error
    return -1;

}
/**
 * @TODO Need to revise getTile and getShot to use a private method as we have
 * repeating code here.
 */
int Board::getTile(int x, int y){

    int Tile;

	//set our tiles to 0 for water, 1 for ship, 2 for hit, 3 for miss
	switch (this->tiles[x][y])
	{
	  case water:
		  Tile = water;
		 break;
	  case ship:
		  Tile = ship;
		 break;
	  case hit:
		  Tile = hit;
		 break;
	  case miss:
		  Tile = miss;
		 break;
	  default:
		  Tile = water;
	};

	return Tile;
}

int Board::getShots(int x, int y){

    int shotTile;

	//set our tiles to 0 for water, 2 for hit, 3 for miss
	//We just test for Water, Hit & Miss.
	switch (this->tiles[x][y])
	{
	  case water:
		  shotTile = water;
		 break;
	  case hit:
		  shotTile = hit;
		 break;
	  case miss:
		  shotTile = miss;
		 break;
	  default:
		  shotTile = water;
	};

	return shotTile;
}

int Board::boardPositionToArray(int ship, string input){
	string stposX = input.substr(0,1);
	int posX;

	if(stposX == "A"){
	  posX = 0;
	}else if(stposX ==  "B"){
	  posX = 1;
	}else if(stposX ==  "C"){
	  posX = 2;
	}else if(stposX ==  "D"){
	  posX = 3;
	}else if(stposX ==  "E"){
	  posX = 4;
	}else if(stposX ==  "F"){
	  posX = 5;
	}else if(stposX ==  "G"){
	  posX = 6;
	}else if(stposX ==  "H"){
	  posX = 7;
	}else if(stposX ==  "I"){
	  posX = 8;
	}else if(stposX ==  "F"){
	  posX = 9;
	}

	string posTemp = input.substr(1,2);
	int posY = (atoi(posTemp.c_str()))-1;
	string direction = input.substr(3,1);
	int dir;
	if(direction == "E"){
		dir = vertical;
	}else if(direction == "N"){
		dir = horizontal;;
	}
	//cout << "pos X is '" << posX << "'";
	//cout << "pos Y is '" << posY << "'";
	//cout << "direction is '" << direction << "'";

	this->placeShip(ship, posX, posY, dir);
	return 1;
}

int Board::markShot(string target){
	string stposX = target.substr(0,1);
	int posX;

	if(stposX == "A"){
	  posX = 0;
	}else if(stposX ==  "B"){
	  posX = 1;
	}else if(stposX ==  "C"){
	  posX = 2;
	}else if(stposX ==  "D"){
	  posX = 3;
	}else if(stposX ==  "E"){
	  posX = 4;
	}else if(stposX ==  "F"){
	  posX = 5;
	}else if(stposX ==  "G"){
	  posX = 6;
	}else if(stposX ==  "H"){
	  posX = 7;
	}else if(stposX ==  "I"){
	  posX = 8;
	}else if(stposX ==  "J"){
	  posX = 9;
	}

	string posTemp = target.substr(1,2);
	int posY = (atoi(posTemp.c_str()))-1;

	return this->fireShot(posX, posY);

}
