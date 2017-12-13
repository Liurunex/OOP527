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
		/*
		 * default constructor
		 */
		Board() = default;

		/**
		* Creates a board with pieces in their initial locations.
		*/
		Board(int w, int h, int t);
		
		/**
		* Destoys this board.
		*/
		virtual ~Board();

		/**
		* Returns the width of this board.
		*
		* @return the width of this board
		*/
		int getWidth() const;

		/**
		* Returns the height of this board.
		*
		* @return the height of this board
		*/
		int getHeight() const;

		/**
		* Returns the index of the player whose turn it is on this board.
		*
		* @return the player whose turn it is
		*/
		int getCurrentPlayer() const;

		/**
		* Determines if the given position is on this board.
		*
		* @return true if and only if the position is on this board
		*/
		bool inBounds(int r, int c) const;
		
		/**
		* Returns the piece at the given position on this board, or
		* nullptr if there is no such piece.
		*
		* @param row a row on this board
		* @param col a column on this board
		*/
		std::shared_ptr<Piece> getPiece(int r, int c);

		/**
		* Returns the piece at the given position on this board, or
		* nullptr if there is no such piece.
		*
		* @param row a row on this board
		* @param col a column on this board
		*/
		std::shared_ptr<const Piece> getPiece(int r, int c) const;

		/**
		* Removes the piece, if any, at the given position on this board.
		*
		* @param row a row on this board
		* @param col a column on this board
		*/
		void removePiece(int r, int c);

		/**
		* Places the given checker at the given location on this board.
		*
		* @param row a row on this board
		* @param col a column on this board
		* @param p a checker
		*/
		void placePiece(int r, int c, std::shared_ptr<Piece> p);

		/**
		* Determines if it is legal to move a piece from the given
		* location to the given location on this board.
		*
		* @param fromR a row on this board
		* @param fromC a column on this board
		* @param toR a row on this board
		* @param toC a column on this board
		* @return true if and only if the move is legal
		*/
		virtual bool isLegalMove(int fromR, int fromC, int toR, int toC) const = 0;

		/**
		* Updates this move to reflect the effects of the given move.
		*
		* @param fromR the starting row of a legal move on this board
		* @param fromC the starting column of a legal move on this board
		* @param toR the ending row of a legal move on this board
		* @param toC the ending column of a legal move on this board
		*/
		virtual void makeMove(int fromR, int fromC, int toR, int toC) = 0;

		/**
		* Determines if the game on this board is over.
		*
		* @return true if and only if the game is over
		*/
		virtual bool gameOver() const = 0;

		/**
		* Returns a printable representation of this board.
		*
		* @return a printable representation of this board
		*/
		virtual std::string toString() const = 0;

		/**
		* Outputs a printable representation of this board to the given stream.
		*
		* @param os an output stream
		* @param board a board
		* @return the output stream
		*/
		friend std::ostream& operator<<(std::ostream& os, const Board& board) {
			return os << board.toString();
		}
		
	protected:

		/**
		* The width of this board.
		*/
		int width;	

		/**
		* The height of this board.
		*/
		int height;

		/**
		* The index of the player whose turn it is.
		*/
		int turn;	

		/**
		* Contains the pieces on this board.  board[r][c] is the piece
		* at row r, column c.  A given entry is nullptr if there is no
		* piece.
		*/
	    std::vector<std::vector<std::shared_ptr<Piece>>> board;	
	};

	
}
  
#endif

