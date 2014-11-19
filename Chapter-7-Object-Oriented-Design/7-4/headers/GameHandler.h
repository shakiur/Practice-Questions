#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "Player.h"

class GameHandler{
    ChessBoard* board;
    Player* player1;
    Player* player2;

    public:
        GameHandler(){
            board = new ChessBoard;

            player1 = new Player("Jack", 1, board);
            player2 = new Player("Jill", 2, board);

            board->displayBoard();
        }
        
};


#endif