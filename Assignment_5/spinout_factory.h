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
		/* the default destructor 
         * no parameters;
         * fucntion: destruct the class members
         */
		~SpinOutFactory() {};

		/* parameter: string input
         * fucntion: call SpinOut(stream) constructor
         */
		SpinOut* puzzleFromString (std::string& init) {
			return new SpinOut(init);
		}
		
		/* parameter: stream input;
         * fucntion: throw exception
         */
		SpinOut* puzzleFromStream (std::ifstream& in) {
			throw "illegal construction";
		}
		
		/* call default SPinOut constructor
         */
		SpinOut* defaultPuzzle () {
			return new SpinOut();
		}
	};

}

#endif
