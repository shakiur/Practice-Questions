#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Player.h"

class GameHandler{
    ChessBoard* board;
    Player* player1;
    Player* player2;

    public:
        GameHandler(){
            board = new ChessBoard;

            player1 = new Player("Player1", 1, board);
            player2 = new Player("Player2", 2, board);

            board->displayBoard();
        }
        
        void play(){
            while(player1->isAlive() && player2->isAlive()){
                player1->play();
                // player2->play();
            }
        }
};


#endif