/*
 * main.cpp
 *
 *  Created on: 04/10/2013
 *      Author: User
 */
#include <iostream>
#include "board.h"
#include "Opponent.h"
using namespace std;
using namespace battleships;

const int player   = 1;
const int opponent = 2;

void displayBoard(Board Board, int type){
	char szLetter[] = "ABCDEFGHIJ";
    //loop and display
    //set our tiles to 0
    cout << "    " << "1 2 3 4 5 6 7 8 9 10" << endl;
    for (int nRow = 0; nRow < 10; nRow++) {
    	cout << " " << szLetter[nRow] << " |";
    	for (int nCol = 0; nCol < 10; nCol++) {
			switch (Board.getTile(nRow, nCol))
				{
				  case water:
					  cout << "~|";
					 break;
				  case ship:
					  if(type == player){
						  cout << "S|";
					  }else{
						  cout << "~|";
					  }
					 break;
				  case hit:
					  cout << "X|";
					 break;
				  case miss:
					  cout << "m|";
					 break;
				  default:
					  cout << "~|";
				};
        };
        cout << endl;
    };
}

void dropShips(string name, string shipType, int shipSize, Board &playerBoard){
    cout << "Commander " << name << ", your "<< shipType <<" is awaiting move orders" << endl
    	 << "command format is [A-F][01-10] [S|E]:" << endl;
    string placeShip;
    cin >> placeShip;
    playerBoard.boardPositionToArray( shipSize, placeShip);
    cout << endl << "----" << "FLEET BOARD" << "----" << endl;
    //place some ships
    displayBoard(playerBoard, player);
}

int fire(string name, Board &opponentBoard){
    cout << "Commander " << name << ", standing by to fire" << endl
    	 << "command format is [A-F][01-10]:" << endl;
    string target;
    cin >> target;
    int result = opponentBoard.markShot(target);
    displayBoard(opponentBoard, opponent);

    return result;
}

int main()
{
    //create a board
    Board playerBoard;
    Board opponentBoard;
    Opponent enemy;

    cout << "   ___  ___ ______________   __________ _________ " << endl;
    cout << "  / _ )/ _ /_  __/_  __/ /  / __/ __/ // /  _/ _ \\" << endl;
    cout << " / _  / __ |/ /   / / / /__/ _/_\\ \\/ _  // // ___/" << endl;
    cout << "/____/_/ |_/_/   /_/ /____/___/___/_//_/___/_/    " << endl;
	cout << "Battleship: Advanced Tactics & Logistic Events Simulator Human Interface Program" << endl << endl << endl;
	cout << "Welcome Commander!" << endl
		 << "Please enter your Callsign for this mission" << endl
		 << "Command Callsign:" << endl;

    string name;

    cin >> name; // read string from console and store it in x

    cout << "Commander " << name << "! We have a developing situation, at 0900 our" << endl
    	 <<	"patrol boat detected, an enemy presence soon after our RADAR system" << endl
    	 << "went dark. Our communication net is also being jammed so you will" << endl
    	 << "only have limited orders available. The President has given us" << endl
    	 << "clearance for a full scale attack. The fleet at your disposal" << endl
    	 << "consists of:" << endl
    	 << "- Nimitz Size-5 Class Air-craft carrier" << endl
    	 << "- Reagan Size-4 Class Battleship" << endl
    	 << "- Ticonderoga Size-3 Class Cruiser" << endl
    	 << "- Collins Size-3 Class Submarine" << endl
    	 << "- Abbot Size-2 class Patrol Boat" << endl << endl;

    cout << "Display battlefield..." << endl;
    cin.ignore();
    cin.get();

    cout << "----" << "FLEET BOARD" << "----" << endl;
    displayBoard(playerBoard, player);

    dropShips( name, "Air-craft Carrier" , 5 , playerBoard);
    dropShips( name, "Battleship" , 4 , playerBoard);
    dropShips( name, "Cruiser" , 3 , playerBoard);
    dropShips( name, "Submarine" , 3 , playerBoard);
    dropShips( name, "Patrol Boat" , 2 , playerBoard);

    cout << "----" << "FLEET BOARD" << "----" << endl;
	displayBoard(playerBoard, player);

    opponentBoard.placeShip(crusier, 1 , 1, vertical);
    opponentBoard.placeShip(carrier, 3 , 2, horizontal);
    opponentBoard.placeShip(battleship, 4 , 4, vertical);
    opponentBoard.placeShip(submarine, 6 , 6, vertical);
    opponentBoard.placeShip(patrol, 8 , 9, horizontal);

    cout << "----" << "ENEMY BOARD" << "----" << endl;
    displayBoard(opponentBoard, opponent);

    int battle = 1;
    while(battle == 1){
		int move = 1;
		while(move == 1){
			move = fire(name, opponentBoard);
		};
		enemy.fireShot(playerBoard);
		cout << "----" << "SIR WE ARE TAKING FIRE!" << "----" << endl;
	    cout << "----" << "FLEET BOARD" << "----" << endl;
		displayBoard(playerBoard, player);
    };

    return 0;
}




