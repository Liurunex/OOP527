#ifndef __SPINOUT_FACTORY_H__
#define __SPINOUT_FACTORY_H__

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include "puzzle_factory.h"
#include "spinout.h"

namespace cs427_527 {
	class SpinOutFactory : public PuzzleFactory {
	public:
		
		~SpinOutFactory() {};

		SpinOut* puzzleFromString (std::string& init) {
			return new SpinOut(init);
		}
		
		SpinOut* puzzleFromStream (std::ifstream& in) {
			throw "illegal construction";
		}
		
		SpinOut* defaultPuzzle () {
			return new SpinOut();
		}
	};

}

#endif
