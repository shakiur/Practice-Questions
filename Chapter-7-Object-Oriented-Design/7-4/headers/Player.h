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
					pawns[i] = new Pawn(i, y_pos_pawn, type);
					board->setBoard(i, y_pos_pawn, pawns[i]);
				}

				// King
				k = new King(x_king_pos, y_pos_other, type);
				board->setBoard(x_king_pos, y_pos_other, k);

				// Queen
				q = new Queen(x_queen_pos, y_pos_other, type);
				board->setBoard(x_queen_pos, y_pos_other, q);

				// Rooks
				rooks = new Rook*[2];
				for(int i = 0; i < 2; i++){
					rooks[i] = new Rook(i*7, y_pos_other, type);
					board->setBoard(i*7, y_pos_other, rooks[i]);
				}

				// Knights
				knights = new Knight*[2];
				for(int i = 0; i < 2; i++){
					knights[i] = new Knight((i * 5) + 1, y_pos_other, type);
					board->setBoard((i*5) + 1, y_pos_other, knights[i]);
				}

				// Bishops
				bishops = new Bishop*[2];
				for(int i = 0; i < 2; i++){
					bishops[i] = new Bishop((i*3) + 2, y_pos_other, type);
					board->setBoard((i*3) + 2, y_pos_other, bishops[i]);
				}
			
		}

		// Getters
		std::string getName() { return name; }

		bool isAlive(){return k->isAlive(); }

		void play(){
			bool valid_piece = false;

			int x_orig;
			int y_orig;

			int x_dest;
			int y_dest;

			// Get valid origin piece
			do{
				
				std::cout << std::endl;
				std::cout << name << " please enter piece to move:\n";
				std::cout << "X: ";
				std::cin >> x_orig;

				std::cout << "Y: ";
				std::cin >> y_orig;

				// Checks if values entered is within scope
				if(x_orig < 0 || y_orig < 0 || x_orig > 7 || y_orig > 7){
					std::cout << "Invalid Chess Piece!\n";
				}
				else{
					// Checks if space is blank
					if(board->checkPieceEmpty(x_orig, y_orig))
						std::cout << "Empty Space Selected!\n";
					// Checks if origin piece belongs to player
					else if(board->matchPlayerPiece(x_orig, y_orig, type))
						valid_piece = true;
					else
						std::cout << "Other Player Chess Piece!\n";
				}
			}
			while(!valid_piece);

			// Get valid destination
			do{
				std::cout << std::endl;
				std::cout << "Origin Piece " 
						  << board->getPiece(x_orig, y_orig)->getAbbr()
						  << board->getPiece(x_orig, y_orig)->getPlayer()
						  << " X|Y:  " 
						  << x_orig << "|" << y_orig << "\n";

				std::cout << name << " please enter destination:\n";
				std::cout << "X: ";
				std::cin >> x_dest;

				std::cout << "Y: ";
				std::cin >> y_dest;

				// Checks if values entered is within scope
				if(x_dest < 0 || y_dest < 0 || x_dest > 7 || y_dest > 7){
					std::cout << "Invalid Chess Piece!\n";
					valid_piece = false;
				}
				else if(board->checkPieceEmpty(x_dest, y_dest)){

					// Check if move is valid
					if(!board->getPiece(x_orig, y_orig)->validMove(x_dest, y_dest)){
						std::cout << "Piece Cannot Move That Way!\n";
						valid_piece = false;
					}
					else{
						// Move piece to new destination
						board->setBoard(x_dest, y_dest, board->getPiece(x_orig, y_orig));
						
						// Update current pieces coordinates
						board->getPiece(x_dest, y_dest)->setPos(x_dest, y_dest);

						// Set old position to NULL
						board->setBoard(x_orig, y_orig, NULL);
						valid_piece = true;
						
					}
				}
				else{
					if(board->matchPlayerPiece(x_dest, y_dest, type)){
						std::cout << "Cannot Replace Your Own Piece!\n";
						valid_piece = false;
					}
					else if(!board->getPiece(x_orig, y_orig)->validMove(x_dest, y_dest)){
						std::cout << "Piece Cannot Move That Way!\n";
						valid_piece = false;
					}
					else{
						valid_piece = true;
						board->getPiece(x_dest, y_dest)->setAlive(false);

						// Move piece to new destination
						board->setBoard(x_dest, y_dest, board->getPiece(x_orig, y_orig));
						
						// Update current pieces coordinates
						board->getPiece(x_dest, y_dest)->setPos(x_dest, y_dest);
						
						// Set old position to NULL
						board->setBoard(x_orig, y_orig, NULL);
						
					}
				}
			}
			while(!valid_piece);


		}

};

#endif