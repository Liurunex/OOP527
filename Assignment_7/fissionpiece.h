#ifndef __FISSIONPIECE_H__
#define __FISSIONPIECE_H__

#include <string>
#include <memory>
#include "piece.h"

namespace cs427_527 {
	class Board;
	
	class FissionPiece : public Piece {
	public:
		/* the constructor to accept two valid inputs to 
		 * construct the board
		 */
		FissionPiece(int p, int r, int c);

		/* the default destructor */
		~FissionPiece();
		
		/**
		* Determines if it is legal to move this checker to the
		* given position on the given board, considering only the
		* movement rules for a checcker.  So this method does not
		* consider turn, can-jump-must-jump rules, or similar rules.
		*
		* @param board a board
		* @param toR a row on that board
		* @param toC a column on that board
		*/
		bool isLegalMove(const Board& board, int toR, int toC) const;

		/**
		* Moves this checker to the given position on the given board,
		* provided the move is legal, considering the movement rules
		* for a checker.
		*
		* @param board a board
		* @param toR a row on that board
		* @param toC a column on that board
		*/
		void makeMove(Board& board, int toR, int toC);

		/**
		* Returns a printable representation of this checker.
		*
		* @return a printable representation of this checker
		*/
		virtual std::string toString() const;

		/**
	     * Returns a HTML representation of this piece.
	     *
	     * @return a HTML representation of this piece.
	     */
		virtual std::string toHTML() const;

	protected:
		virtual void hitRemove (Board& board, int hitR, int hitC);
		
	};
}

#endif