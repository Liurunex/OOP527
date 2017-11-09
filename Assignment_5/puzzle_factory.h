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
		/* default destructor */
		virtual ~PuzzleFactory() {};

		/* virtual fucntion that take a string input to construct game obejct */
		virtual Puzzle* puzzleFromString (std::string& init) = 0;
		
		/* virtual fucntion that take a stream input to construct game obejct */
		virtual Puzzle* puzzleFromStream (std::ifstream& in) = 0;
		
		/* virtual default fucntion to construct game obejct */
		virtual Puzzle* defaultPuzzle () = 0;
	};

}

#endif
