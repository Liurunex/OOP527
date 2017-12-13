#ifndef __FISSIONBOARD_H__
#define __FISSIONBOARD_H__

#include <string>
#include <iostream>
#include <memory>
#include "board.h"

namespace cs427_527 {
	class Piece;
	class FissionBoard : public Board{
	public:
		enum Color { WHITE, BLACK };
		
		/* the default constructor */
		FissionBoard();

		/* the constructor to accept two string as input
     	 * and check if the two string can be converted 
     	 * to a valid input and then call the correct constructor
		*/
		FissionBoard(char *ws, char *hs);

		/* the constructor to accept two valid inputs to 
		 * construct the board
		 */
		FissionBoard(int w, int h);
		
		/* the default destructor */
		~FissionBoard();

		/**
	     * Returns the color of this board at the given position.
	     *
	     * @param row a row on this board
	     * @param col a column on this board
	     * @return the color of that position.
	     */
	    int getBoardColor(int row, int col) const;
	    
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
	    bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

	    /**
	     * Updates this move to reflect the effects of the given move.
	     *
	     * @param fromR the starting row of a legal move on this board
	     * @param fromC the starting column of a legal move on this board
	     * @param toR the ending row of a legal move on this board
	     * @param toC the ending column of a legal move on this board
	     */
	    void makeMove(int fromR, int fromC, int toR, int toC);

	    /**
	     * Determines if the game on this board is over.
	     *
	     * @return true if and only if the game is over
	     */
	    bool gameOver() const;

	    /**
	     * Returns a printable representation of this board.
	     *
	     * @return a printable representation of this board
	     */
	    std::string toString() const;

	    /**
	     * Determines if the game on this board is draw.
	     *
	     * @return true if and only if the game is draw
	     */
	    bool isDraw() const;

	    /**
	     * Returns a HTML representation of this board.
	     *
	     * @return a HTML representation of this board
	     */
	    void toHTML() const;
		
		};
}

#endif