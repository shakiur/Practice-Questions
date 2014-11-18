/*
Design a chess game using object oriented principles
*/

#include <iostream>
#include "headers/ChessBoard.h"
#include "headers/ChessPiece.h"

int main(){
	ChessBoard * cb = new ChessBoard;
	cb->displayBoard();

	Pawn* p = new Pawn("Pawn1", 'P', 0, 0);
}