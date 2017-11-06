#ifndef __CONWAY_FACTORY_H__
#define __CONWAY_FACTORY_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include "puzzle_factory.h"
#include "conway.h"
#include "puzzle.h"

using cs427_527::Puzzle;

namespace cs427_527 {
	class ConwayFactory : public PuzzleFactory {
	public:

		ConwayFactory() {}
		
		~ConwayFactory() {};

		Puzzle* puzzleFromString (std::string& init) {
			throw "illegal construction";
		}
		
		Puzzle* puzzleFromStream (std::ifstream& in) {
			return new cs427_527::Conway(in);
		}
		
		Puzzle* defaultPuzzle () {
			return new cs427_527::Conway();
		}
	};

}

#endif
