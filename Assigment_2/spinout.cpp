#include <string.h>
#include <stdio.h>
#include <iostream>
#include "spinout.h"

namespace HW
{
	SpinOut::SpinOut() {
		memset(board,'-',sizeof(board));
	}

	SpinOut::SpinOut(const std::string& s) {
		if (!s.length()) {
			 memset(board,'-',sizeof(board));
		}
		else {
			for (size_t i = 0; i < s.length(); ++ i)
				this->board[i] = s.at(i);
		}
	}

	SpinOut::~SpinOut() {}

	void 
	SpinOut::boardPrint() const {
		for (int i = 0; i < SIZE; ++ i)
			std::cout << board[i];
		std::cout << "\n";
	}
	
	bool 
	SpinOut::isLegalMove(int i) const {
		if (i >= SIZE || i < 0) return false;
		if (i+1 == SIZE) return true;

		if (i+1 < SIZE && board[i+1] == '/')
			for (int j = i+2; j < SIZE; ++j)
				if (board[j] != '-')
					return false;

		return true;
	}

	void 
	SpinOut::makeMove(int i) {
		if (isLegalMove(i)) {
			board[i] = board[i] == '-' ? '/':'-';
			user_move ++;
			boardPrint();
		}
		else
			std::cout << "Woops: illegal move." << std::endl;
	}

	int 
	SpinOut::totalMoves() const {
		return user_move;
	}

	bool 
	SpinOut::isSolved() const {
		for (int i = 0; i < SIZE; ++ i)
			if (board[i] == '/')
				return false;
		return true;
	}

	std::string 
	SpinOut::toString() const {
		return "";
	}
    
}

int main (int argc, char** argv) {
	HW::SpinOut* gameObejct;
	//int mode = 0;
	if (argc >= 2 && !strcmp(argv[1], "-i")) {
		if (argc == 2)
			gameObejct = new HW::SpinOut();
		else {
			std::string board(argv[2]);
			if (board.length() != 7 || 
				board.find_first_not_of("-/") != std::string::npos) {
				std::cout << "Error: invaild board input\n";
				return 1;
			}
			gameObejct = new HW::SpinOut(board);
		}
	}

	//SpinOut* gameObejct = new SpinOut();
	//gameObejct->boardPrint();
	
    return 0;
}
