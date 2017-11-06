#ifndef __PUZZLE_FACTORY_H__
#define __PUZZLE_FACTORY_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include "puzzle.h"

namespace cs427_527 {
	class PuzzleFactory {
	public:

		virtual ~PuzzleFactory() {};

		virtual Puzzle* puzzleFromString (std::string& init) = 0;
		
		virtual Puzzle* puzzleFromStream (std::ifstream& in) = 0;
		
		virtual Puzzle* defaultPuzzle () = 0;
	};

}

#endif
