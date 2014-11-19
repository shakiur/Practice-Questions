#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard{
	char** board;
	int x;
	int y;

	public:
		ChessBoard(){
			x = 8;
			y = 8;
			board = new char*[8];

			for(int i = 0; i < x; i++){
				board[i] = new char[8];

				for(int j = 0; j < y; j++){
					board[i][j] = 'X';
				}
			}
		}

		void displayBoard(){
			for(int i = 0; i < y; i++){
				for(int j = 0; j < x; j++){
					std::cout << " " << board[i][j];
				}
				std::cout << std::endl;

			}
		}

		void setBoard(int x, int y, char c){
			board[y][x] = c;
		}
};

#endif