#ifndef __SPINOUT_FACTORY_H__
#define __SPINOUT_FACTORY_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include "puzzle_factory.h"
#include "spinout.h"
#include "puzzle.h"

using cs427_527::Puzzle;

namespace cs427_527 {
	class SpinOutFactory : public PuzzleFactory {
	public:
		
		SpinOutFactory() {}
		
		~SpinOutFactory() {};

		Puzzle* puzzleFromString (std::string& init) {
			return new cs427_527::SpinOut(init);
		}
		
		Puzzle* puzzleFromStream (std::ifstream& in) {
			throw "illegal construction";
		}
		
		Puzzle* defaultPuzzle () {
			return new cs427_527::SpinOut();
		}
	};

}

#endif
