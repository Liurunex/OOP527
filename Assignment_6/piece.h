#ifndef __PIECE_H__
#define __PIECE_H__

#include <string>

namespace cs427_527 {
	
	class Board;
	
	class Piece {
	public:

		/**
		* Creates a piece owned by the given player at the given position.
		*
		* @param p 0 or 1
		* @param r a nonnegative integer
		* @param c a nonnegative integer
		*/
		Piece(int p, int r, int c);
		
		/**
		* Destroys this piece.
		*/
		virtual ~Piece();

		/* Determines if it is legal to move this piece to the
		* given position on the given board, considering only the
		* movement rules for a checcker.  So this method does not
		* consider turn, can-jump-must-jump rules, or similar rules.
		*
		* @param board a board
		* @param toR a row on that board
		* @param toC a column on that board
		*/
		virtual bool isLegalMove(const Board& board, int toR, int toC) const = 0;

		/**
		* Moves this piece to the given position on the given board,
		* provided the move is legal, considering the movement rules
		* for a piece.
		*
		* @param board a board
		* @param toR a row on that board
		* @param toC a column on that board
		*/
		virtual void makeMove(Board& board, int toR, int toC) = 0;

		/**
		* Returns the index of the player this piece belongs to.
		*
		* @return the index of the owner
		*/
		int getPlayer() const;

		/**
		* Returns a printable representation of this piece.
		*
		* @return a printable representation of this piece
		*/
		virtual std::string toString() const = 0;
		
	protected:
		
		/**
		* The index of the player this piece belongs to.
		*/
		int player;

		/**
		* The row of the position of this piece.
		*/
		int row;

		/**
		* The column of the position of this piece.
		*/
		int col;
	};
}

#endif
