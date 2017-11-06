#ifndef __PUZZLE_FACTORY_H__
#define __PUZZLE_FACTORY_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include "puzzle.h"

using cs427_527::Puzzle;

namespace cs427_527 {
	class PuzzleFactory {
	public:

		PuzzleFactory();

		virtual ~PuzzleFactory();

		virtual Puzzle* puzzleFromString (std::string& init) = 0;
		
		virtual Puzzle* puzzleFromStream (std::ifstream& in) = 0;
		
		virtual Puzzle* defaultPuzzle () = 0;
	};

}

#endif
