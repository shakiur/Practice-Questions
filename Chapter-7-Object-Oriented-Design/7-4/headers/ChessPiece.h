#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <cmath>

class ChessPiece{
	protected:
		std::string name;
		char abbr;
		int x_pos;
		int y_pos;
		bool alive;

		int player;

	public:
		ChessPiece(std::string n, char a, int x, int y, int p) : 
			name(n), abbr(a), x_pos(x), y_pos(y), player(p), alive(true) {}

		// Getters
		std::string getName() { return name; }
		char getAbbr() { return abbr; }
		int get_x_pos() { return x_pos; }
		int get_y_pos() { return y_pos; }
		bool isAlive() { return alive; }
		virtual bool validMove(int x, int y) {return true;}
		int getPlayer() { return player; }

		// Setters
		void setPos(int x, int y){
			x_pos = x;
			y_pos = y;
		}
		void setAlive(bool b) { alive = b; }

};

class Pawn : public ChessPiece{

	public:
		Pawn(int x, int y, int p) : 
			ChessPiece("Pawn", 'P', x, y, p) {}

		bool validMove(int x, int y){
			// Checks if piece moves 1 spot forward or 1 spot diagonal
			return (	std::abs(y_pos - y) == 1
							&& 
						((x == x_pos) || x == (x_pos + 1)));
		}
};

class King : public ChessPiece{

	public: 
		King(int x, int y, int p) :
			ChessPiece("King", 'K', x, y, p) {}

		bool validMove(int x, int y){
			// Checks if piece moved 1 position
			return (
					((x == x_pos) && (y == (y_pos + 1)))
						||
					((x == x_pos) && (y == (y_pos - 1)))
						||
					((x == (x_pos + 1)) && (y == y_pos))
						||
					((x == (x_pos - 1)) && (y == y_pos))
				);
		}
};

class Queen : public ChessPiece{

	public:
		Queen(int x, int y, int p) : 
			ChessPiece("Queen", 'Q', x, y, p) {}

		bool validMove(int x, int y){
			// Checks if diagonal move was made
			// or vertical/horizontal move was made
			return 	(	// Diagnoal
						( std::abs(x - x_pos) == std::abs(y - y_pos) )
							||
						// Vertical
						( x == x_pos)
							||
						// Horizontal
						( y == y_pos)
					);
		}
};


class Bishop : public ChessPiece{

	public:
		Bishop(int x, int y, int p) : 
			ChessPiece("Bishop", 'B', x, y, p) {}

		bool validMove(int x, int y){
			// Checks if new position is diagonal
			return std::abs(x - x_pos) == std::abs(y - y_pos);
		}

};

class Rook : public ChessPiece{
	public:
		Rook(int x, int y, int p) : 
			ChessPiece("Rook", 'R', x, y, p) {}

		bool validMove(int x, int y){
			// Checks if new position is vertical or horizontal
			return 	(
						(x == x_pos)
							||
						(y == y_pos)
					);
		}
};

class Knight : public ChessPiece{

	public:
		Knight(int x, int y, int p) :
			ChessPiece("Knight", 'N', x, y, p) {}

		bool validMove(int x, int y){
			// Checks if new position is L in any direction
			return 	(
						(y == (y_pos + 2) && (x == (x_pos + 1)))
							||
						(y == (y_pos + 2) && (x == (x_pos - 1)))
							||
						(y == (y_pos - 2) && (x == (x_pos + 1)))
							||
						(y == (y_pos - 2) && (x == (x_pos - 1)))
							||
						(x == (x_pos + 2) && (y == (y_pos + 1)))
							||
						(x == (x_pos + 2) && (y == (y_pos - 1)))
							||
						(x == (x_pos - 2) && (y == (y_pos + 1)))
							||
						(x == (x_pos - 2) && (y == (y_pos - 1)))
					);
		}
};

#endif