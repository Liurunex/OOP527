#include "spinout.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib> 

using cs427_527::SpinOut;
using std::strcmp;
using std::string;
using std::endl;
using std::stoi;
using std::cout;
using std::cin;

int main (int argc, char** argv) {
	if (argc < 2) {
		cout << "Error: invalid input arguments\n";
		return 1;
	}
	SpinOut* gameObejct;
	/* handle interactive mdoe */
	if (argc >= 2 && !strcmp(argv[1], "-i")) {
		if (argc > 3) cout << "Error: excessed input will be ignored\n";
		if (argc == 2)
			gameObejct = new SpinOut();
		else {
			string board(argv[2]);
			try {
				gameObejct = new SpinOut(board);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		gameObejct->interactive_mode();
	}

	/* hadnle non-interactive mode*/
	else if (argc >= 2){
		/* determine which constructor to use and new the object */
		string board(argv[1]);
		int start_position = -1; 
		if (board.length() == 1 && isdigit(board[0])) {
			start_position = 1;
			gameObejct = new SpinOut();
		}
		else {
			start_position = 2;
			try {
				gameObejct = new SpinOut(board);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		}
		gameObejct->non_interactive_mode(start_position, argc, argv);
	}
	
    return 1;
}