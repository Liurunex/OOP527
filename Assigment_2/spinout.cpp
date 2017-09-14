#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include "spinout.h"

namespace HW
{
	SpinOut::SpinOut() {
		memset(board, '/', sizeof(board));
	}

	SpinOut::SpinOut(const std::string& s) {
		if (!s.length()) {
			 memset(board, '/', sizeof(board));
		}
		else {
			for (size_t i = 0; i < s.length(); ++ i)
				this->board[i] = s.at(i);
		}
	}

	SpinOut::~SpinOut() {}

	void 
	SpinOut::boardPrint() const {
		std::cout << toString() << std::endl;
	}
	
	bool 
	SpinOut::isLegalMove(int i) const {
		if (i >= SIZE || i < 0) return false;
		if (i+1 == SIZE) return true;

		if (board[i+1] == '-') return false;
		else {
			for (int j = i+2; j < SIZE; ++j)
				if (board[j] == '/')
					return false;
		}
		return true;
	}

	void 
	SpinOut::makeMove(int i) {
		if (isLegalMove(i)) {
			board[i] = board[i] == '-' ? '/':'-';
			this->moves.push_back(i);
		}	
	}

	int 
	SpinOut::totalMoves() const {
		return moves.size();
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
		std::string return_res(board);
		return return_res;
	}
    
    void
    SpinOut::interactove_mode() {
    	do {
			this->boardPrint();
			int index = -1;
			if (std::cin >> index) {
				if (this->isLegalMove(index))
					this->makeMove(index);
				else std::cout << "illegal move" << std::endl;
			}
			else {
				std::cout << "whoops: you gived it up :)\n";
				return;
			}
		} while (!this->isSolved());
		if (this->isSolved())
			std::cout << this->totalMoves() << " moves\n";
    }

    void 
    SpinOut::non_interactove_mode(int& start_position, int& argc,
    	char** argv) {
		int index = start_position;
		do {
			if (index >= argc) break;
			std::string candiate_move(argv[index]);
			if (candiate_move.length() == 1 && isdigit(candiate_move[0])) {
				int rotate_pos = std::stoi(candiate_move); 
				if (isLegalMove(rotate_pos))
					makeMove(rotate_pos);
				else {
					std::cout << "SpinOut: illegal move " << rotate_pos << " in position "
					<< index << " for " << toString() << std::endl;
					return;
				}
				index ++;
			}
			else {
				std::cout << "Error: invalid move input\n";
				return;
			}
		} while (!this->isSolved());

		if (!isSolved()) this->boardPrint();
		else std::cout << "SOLVED\n";
    }
}

int main (int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: invalid input arguments";
		return 1;
	}
	HW::SpinOut* gameObejct;
	/* NOTICE: strcmp is a c-style fucntion */
	/* handle interactive mdoe */
	if (argc >= 2 && !strcmp(argv[1], "-i")) {
		/* determine which constructor to use and new the object */
		if (argc > 3) std::cout << "Error: excessed input will be ignored\n";
		if (argc == 2)
			gameObejct = new HW::SpinOut();
		else {
			std::string board(argv[2]);
			if (board.length() != BOARD_SIZE || 
				board.find_first_not_of("-/") != std::string::npos) {
				std::cout << "Error: invaild board input\n";
				return 1;
			}
			gameObejct = new HW::SpinOut(board);
		}
		/* interactive mode start */
		gameObejct->interactove_mode();
	}
	/* hadnle non-interactive mode*/
	else if (argc >= 2){
		/* determine which constructor to use and new the object */
		std::string board(argv[1]);
		int start_position = -1; 
		if (board.length() == 1 && isdigit(board[0])) {
			start_position = 1;
			gameObejct = new HW::SpinOut();
		}
		else if (board.length() == BOARD_SIZE && 
				board.find_first_not_of("-/") == std::string::npos) {
			start_position = 2;
			gameObejct = new HW::SpinOut(board);
		}
		else {
			std::cout << "Error: invaild input in non-interactive mdoe\n";
			return 1;
		}
		/* non-interactive mode start */
		gameObejct->non_interactove_mode(start_position, argc, argv);
	}
	
    return 1;
}
