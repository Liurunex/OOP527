#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include <string>
#include <iostream>
#include "puzzle_move.h"

namespace cs427_527 {
	class Puzzle {
	public:
		/* default destructor */
		virtual ~Puzzle() {}

		/* parameter: input stream;
         * virtual fucntion: read move positions from stream, construct the PuzzleMove obejct
         * and return its pointer
         */
		virtual PuzzleMove* readMove(std::istream& movesIn) = 0;

		/* parameter: a PuzzleMove pointer which stores the index of the indicated disk;
         * virtual fucntion: take an move pointer, extracted the position, and judge if it was legal
         */
		virtual bool isLegalMove(PuzzleMove* move) const = 0;

		/* parameter: a PuzzleMove pointer which stores the index of the indicated disk;
         * virtual fucntion: it first call isLegaMove to determine if the index is valid; 
         * then make that move on board
         */
		virtual void makeMove(PuzzleMove* move) = 0;

		/* no parameter;
         * virtual fucntion: determines if the current object is in 
         * its solved configuration
         */
		virtual bool isSolved() const = 0;

		/* no parameter;
         * virtual fucntion: count the number of legal moves performed on 
         * the current object since it was created.
         */
		virtual int totalMoves() const = 0;

		/* no parameter;
         * virtual fucntion: return a string representation of 
         * the current object in the same format as that 
         * passed to the second version of the constructor.
         */
		virtual std::string toString() const = 0;

		/* overload the opeartor << */
		friend std::ostream& operator<<(std::ostream& out, const Puzzle& a) {
			return out << a.toString();
		}
	};
}

#endif
