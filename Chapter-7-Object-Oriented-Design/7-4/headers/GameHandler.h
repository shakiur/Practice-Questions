#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "ChessBoard.h"
#include "ChessPiece.h"

class GameHandler{
    ChessBoard* board;

    public:
        GameHandler(){
            board = new ChessBoard;
        }
};


#endif