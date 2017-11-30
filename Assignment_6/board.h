#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace cs427_527 {
	class Piece;

	class Board{
	
	public:
		Board(int w, int h, int t) : width(w), height(h), turn(t),
			board(h, std::vector<std::shared_ptr<Piece>>(w, nullptr)) {}
		
		virtual ~Board() {}

		int getWidth() const { return width; }

		int getHeight() const { return height; }

		int getCurrentPlayer() const { return turn; }

		bool inBounds(int r, int c) const {
			return r >= 0 && r < height && c >= 0 && c < width;
		}
		
		
		virtual std::shared_ptr<Piece> getPiece(int row, int col) = 0;

		virtual std::shared_ptr<const Piece> getPiece(int row, int col) const = 0;

		virtual void removePiece(int row, int col) = 0;

		virtual void placePiece(int row, int col, std::shared_ptr<Piece> p) = 0;

		virtual int getBoardColor(int row, int col) const = 0;

		virtual bool isLegalMove(int fromR, int fromC, int toR, int toC) const = 0;

		virtual void makeMove(int fromR, int fromC, int toR, int toC) = 0;

		virtual bool gameOver() const = 0;

		virtual std::string toString() const = 0;

		friend std::ostream& operator<<(std::ostream& os, const Board& board) {
			return os << board.toString();
		}
		
	protected:

		int width;	

		int height;

		int turn;	

	    std::vector<std::vector<std::shared_ptr<Piece>>> board;	
	};

	
}
  
#endif

