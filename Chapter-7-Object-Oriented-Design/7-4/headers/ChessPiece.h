#ifndef CHESSPIECE_H
#define CHESSPIECE_H

class ChessPiece{
	protected:
		std::string name;
		char abbr;
		int x_pos;
		int y_pos;
		bool alive;

	public:
		ChessPiece(std::string n, char a, int x, int y) : 
			name(n), abbr(a), x_pos(x), y_pos(y), alive(true) {}

		// Getters
		std::string getName() { return name; }
		char getAbbr() { return abbr; }
		int get_x_pos() { return x_pos; }
		int get_y_pos() { return y_pos; }
		bool isAlive() { return alive; }
		bool validMove(int x, int y);

};

class Pawn : public ChessPiece{

	public:
		Pawn(std::string n, char a, int x, int y) : 
			ChessPiece(n, a, x, y) {}

		bool validMove(int x, int y){
			return (	(y == (y_pos + 1)) 
							&& 
						((x == x_pos) || x == (x_pos + 1)));
		}
};

#endif