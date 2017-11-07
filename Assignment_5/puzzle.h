#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include <string>
#include <iostream>
#include "puzzle_move.h"

namespace cs427_527 {
	class Puzzle {
	public:

		virtual ~Puzzle() {}

		virtual PuzzleMove* readMove(std::istream& movesIn) = 0;

		virtual bool isLegalMove(PuzzleMove* move) const = 0;

		virtual void makeMove(PuzzleMove* move) = 0;

		virtual bool isSolved() const = 0;

		virtual int totalMoves() const = 0;

		virtual std::string toString() const = 0;

		friend std::ostream& operator<<(std::ostream& out, const Puzzle& a) {
			return out << a.toString();
		}
	};
}

#endif