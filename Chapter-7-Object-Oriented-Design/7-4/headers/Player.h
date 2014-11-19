#ifndef PLAYER_H
#define PLAYER_H

class Player{

	// Basic info
	std::string name;
	int type;
	ChessBoard* board;

	// Chess Pieces
	Pawn** pawns;
	King* k;
	Queen* q;
	Rook** rooks;
	Bishop** bishops;
	Knight** knights;

	public:
		// Constructors: Creates pieces & places on board
		Player(std::string n, int t, ChessBoard* b) : name(n), type(t), board(b) {
			int y_pos_pawn;
			int y_pos_other;

			int x_king_pos;
			int x_queen_pos;

			if(type == 1){
				y_pos_pawn = 1;
				y_pos_other = 0;

				x_king_pos = 4;
				x_queen_pos = 3;
			}
			else{
				y_pos_pawn = 6;
				y_pos_other = 7;

				x_king_pos = 3;
				x_queen_pos = 4;
			}

				// Player pieces / positions on board

				// Pawns
				pawns = new Pawn*[8];
				for(int i = 0; i < 8; i++){
					pawns[i] = new Pawn(i, y_pos_pawn);
					board->setBoard(i, y_pos_pawn, pawns[i]->getAbbr());
				}

				// King
				k = new King(x_king_pos, y_pos_other);
				board->setBoard(x_king_pos, y_pos_other, k->getAbbr());

				// Queen
				q = new Queen(x_queen_pos, y_pos_other);
				board->setBoard(x_queen_pos, y_pos_other, q->getAbbr());

				// Rooks
				rooks = new Rook*[2];
				for(int i = 0; i < 2; i++){
					rooks[i] = new Rook(i*7, y_pos_other);
					board->setBoard(i*7, y_pos_other, rooks[i]->getAbbr());
				}

				// Knights
				knights = new Knight*[2];
				for(int i = 0; i < 2; i++){
					knights[i] = new Knight((i * 5) + 1, y_pos_other);
					board->setBoard((i*5) + 1, y_pos_other, knights[i]->getAbbr());
				}

				// Bishops
				bishops = new Bishop*[2];
				for(int i = 0; i < 2; i++){
					bishops[i] = new Bishop((i*3) + 2, y_pos_other);
					board->setBoard((i*3) + 2, y_pos_other, bishops[i]->getAbbr());
				}
			
		}

};

#endif