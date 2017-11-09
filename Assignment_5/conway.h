#ifndef __CONWAY_H__
#define __CONWAY_H__

#include <string>
#include <vector>
#include <iostream>
#include "puzzle.h"

namespace cs427_527 {
	class Conway : public Puzzle {
	public:
		/* the default constructor 
         * no parameters;
         * initial the board on default setting
         */
		Conway();

		/* the override constructor with board setting: 
         * parameters: input stream
         * fucntion: create a puzzle whose initial state is read from the given stream.
         */
		Conway(std::istream& instream);

		/* copy constructor 
         * parameter: reference of a puzzle game object 
         * fucntion: creates an independent copy of the given puzzle state 
         * (changes to the new copy shouldn't affect the original).
		 */
		Conway(const Conway& a);

		/* move constructor 
		 * parameter: right value reference of a game object
  		 * function copy the given puzzle state's representation and leaves 
  		 * that puzzle in a valid (destructable) state
		 */
		Conway(Conway&& a);

		/* assignment operator 
		 * parameter: reference of a puzzle game object 
		 * fucntion: makes the puzzle on the left of the assignment operator an independent 
		 * copy of the puzzle on the right and returns a reference.
 		 */
		Conway& operator=(const Conway& a);

		/* move assignment operator 
		 * parameter:right value reference of a game object
		 * fucntion: copy state of the puzzle on the right of the assignment operator 
		 * into the puzzle on the left, leaving the puzzle on the right in a valid 
		 * (destructable) state, and returns a reference to the puzzle on the left.
		 */
		Conway& operator=(Conway&& a);

		/* the default destructor 
         * no parameters;
         * fucntion: destruct the class members
         */
		~Conway();

		/* parameter: input stream;
		* fucntion: read move positions from stream, construct the PuzzleMove obejct
		* and return its pointer
		*/
		PuzzleMove* readMove(std::istream& movesIn);

		/* parameter: a PuzzleMove pointer which stores the index of the indicated disk;
         * fucntion: take an move pointer, extracted the position, representing the row and 
         * column of the position on the board to move from and to move to and determines whether 
         * such a move is legal according to the rules of the puzzle. If either of the positions
         * is not on the board then the move is illegal.
         */
		bool isLegalMove(PuzzleMove* move) const;

		/* parameter: a PuzzleMove pointer which stores the index of the indicated disk;
         * fucntion: take a legal move represented by integers giving the row and 
         * column of the position on the board to move from and to move to and modifies 
         * the current object to reflect the result of that move.
         */
		void makeMove(PuzzleMove* move);

		/* no parameter;
         * fucntion: determines determines if the current object is in its 
         * solved configuration (some piece in the top row)
         */
		bool isSolved() const;

		/* no parameter;
         * fucntion: count the number of legal moves performed since the initial 
         * state of the original object
         */
		int totalMoves() const;

		/* no parameter;
         * fucntion: return a string representation of 
         * the game board configuration
         */
		std::string toString() const;

	private:    
		int rowSize = 5;
		int colSize = 6;
		bool solved = false;
		int moves   = 0;
		char** board;
	};
}

#endif
