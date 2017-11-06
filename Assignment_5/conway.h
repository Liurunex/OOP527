#ifndef __CONWAY_H__
#define __CONWAY_H__

#include <string>
#include <vector>
#include <iostream>
#include "puzzle.h"
#include "puzzle_move.h"

using cs427_527::PuzzleMove;

namespace cs427_527 {
	class Conway : public Puzzle {
	public:

		Conway();

		Conway(std::istream& instream);

		Conway(const Conway& a);

		Conway(Conway&& a);

		Conway& operator=(const Conway& a);

		Conway& operator=(Conway&& a);

		~Conway();

		PuzzleMove* readMove(std::istream& movesIn);

		bool isLegalMove(PuzzleMove* move) const;

		void makeMove(PuzzleMove* move);

		bool isSolved() const;

		int totalMoves() const;

		std::string toString() const;

	private:    
		int rowSize = 5;
		int colSize = 6;
		bool solved = false;
		int moves   = 0;
		char** board;
	};

	std::ostream& operator<<(std::ostream& out, const Conway& a);
}

#endif
