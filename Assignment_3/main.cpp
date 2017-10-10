#include "spinout.h"
#include <string>
#include <cstring>

using cs427_527::SpinOut;
using std::strcmp;
using std::string;

int main (int argc, char** argv) {
	SpinOut* gameObejct;
	/* handle interactive mdoe */
	if (argc >= 2 && !strcmp(argv[1], "-i")) {
		if (argc == 2)
			gameObejct = new SpinOut();
		else {
			string board(argv[2]);
			gameObejct = new SpinOut(board);
		}
		gameObejct->interactive_mode();
	}

	/* hadnle non-interactive mode*/
	else {
		int start_position = -1; 
		if (argc < 2) {
			start_position = 1;
			gameObejct = new SpinOut();
		}
		else {
			string board(argv[1]);
			bool isNumber = true;
			for (char bchar:board) {
				if (!isdigit(bchar)) {
					isNumber = false;
					break;
				}
			}
			if (isNumber) {
				start_position = 1;
				gameObejct = new SpinOut();
			}
			else {
				start_position = 2;
				gameObejct = new SpinOut(board);
			}
		}
		gameObejct->non_interactive_mode(start_position, argc, argv);
	}
	
    return 1;
}