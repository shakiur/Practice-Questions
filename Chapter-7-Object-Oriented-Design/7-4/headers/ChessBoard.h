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
			for(int i = 0; i < x; i++){
				for(int j = 0; j < y; j++){
					std::cout << " " << board[i][j];
				}
				std::cout << std::endl;

			}
		}
};

#endif