#include "conway.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

using cs427_527::Conway;
using std::strcmp;
using std::string;
using std::filebuf;
using std::istream;

int main (int argc, char** argv) {
	Conway* gameObejct;
	/* handle interactive mdoe */
	if (argc >= 2 && !strcmp(argv[1], "-i")) {
		if (argc == 2)
			gameObejct = new Conway();
		else if (!strcmp(argv[2], "-f") && argc > 3) {
			string inputfile(argv[3]);
			try {
				filebuf fb;
				if (fb.open(inputfile, std::ios::in)) {
					istream binfo(&fb);
					gameObejct = new Conway(binfo);
					fb.close();
				}
				else return 1;
			}
			catch (const char* msg) {
				//std::cout << msg << std::endl;
				return 1;
			}
		}
		else return 1;
		gameObejct->interactive_mode();
	}

	/* hadnle non-interactive mode*/
	else {
		int start_position = -1; 
		if (argc < 2 || strcmp(argv[1], "-f")) {
			start_position = 1;
			gameObejct = new Conway();
		}
		else if (argc >= 3 && !strcmp(argv[1], "-f")){
			string inputfile(argv[2]);
			start_position = 3;
			try {
				filebuf fb;
				if (fb.open(inputfile, std::ios::in)) {
					istream binfo(&fb);
					gameObejct = new Conway(binfo);
					fb.close();
				}
				else return 1;
			}
			catch (const char* msg) {
				//std::cout << msg << std::endl;
				return 1;
			}
		}
		else return 1;
		gameObejct->non_interactive_mode(start_position, argc, argv);
	}
	
    return 1;
}