#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"

class ChessBoard{
	ChessPiece*** board;
	int x;
	int y;

	public:
		ChessBoard(){
			x = 8;
			y = 8;
			
			board = new ChessPiece**[8];

			for(int i = 0; i < x; i++){
				board[i] = new ChessPiece*[8];

				for(int j = 0; j < y; j++){
					board[i][j] = NULL;
				}
			}
			
		}

		void displayBoard(){

			// Display X-axis
			std::cout << "  X|";

			for(int i = 0; i < y; i++)
				std::cout << "  " << i;

			std::cout << std::endl;
			std::cout << "Y" << std::endl;
			std::cout << "--" << std::endl;

			for(int i = 0; i < y; i++){
				// Display Y axis
				std::cout << i << "   ";

				for(int j = 0; j < x; j++){
					if(board[i][j] == NULL)
						std::cout << " " << "--";
					else
						std::cout << " " << board[i][j]->getAbbr()
										 << board[i][j]->getPlayer();
				}
				std::cout << std::endl;

			}
		}

		void setBoard(int x, int y, ChessPiece* c){
			board[y][x] = c;
		}

		bool matchPlayerPiece(int x, int y, int p){
			return p == board[y][x]->getPlayer();
		}

		bool checkPieceEmpty(int x, int y){
			return board[y][x] == NULL;
		}

		ChessPiece* getPiece(int x, int y){
			return board[y][x];
		}
};

#endif