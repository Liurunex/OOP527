#ifndef __PIECE_H__
#define __PIECE_H__

#include <string>

namespace cs427_527 {
	
	class Board;
	
	class Piece {
	public:
		Piece(int p, int r, int c): player(p), row(r), col(c) {}
		
		virtual ~Piece() {}

		virtual bool isLegalMove(const Board& board, int toR, int toC) const = 0;

		virtual void makeMove(Board& board, int toR, int toC) = 0;

		int getPlayer() const { return player; }

		virtual std::string toString() const = 0;
		
	protected:
		
		int player;

		int row;

		int col;
	};
}

#endif
