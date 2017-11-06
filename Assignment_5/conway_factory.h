#ifndef __CONWAY_FACTORY_H__
#define __CONWAY_FACTORY_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include "puzzle_factory.h"
#include "conway.h"

namespace cs427_527 {
	class ConwayFactory : public PuzzleFactory {
	public:
		
		~ConwayFactory() {};

		Conway* puzzleFromString (std::string& init) {
			throw "illegal construction";
		}
		
		Conway* puzzleFromStream (std::ifstream& in) {
			return new Conway(in);
		}
		
		Conway* defaultPuzzle () {
			return new Conway();
		}
	};

}

#endif
