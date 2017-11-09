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
		/* the default destructor 
         * no parameters;
         * fucntion: destruct the class members
         */
		~ConwayFactory() {};

		/* parameter: string input;
         * fucntion: throw exception
         */
		Conway* puzzleFromString (std::string& init) {
			throw "illegal construction";
		}
		
		/* parameter: stream input
         * fucntion: call Conway(stream) constructor
         */
		Conway* puzzleFromStream (std::ifstream& in) {
			return new Conway(in);
		}
		
		/* call default Conway constructor
         */
		Conway* defaultPuzzle () {
			return new Conway();
		}
	};

}

#endif
