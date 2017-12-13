#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <stdlib.h> 

#include "fissionboard.h"
#include "board.h"

using cs427_527::FissionBoard;
using cs427_527::Board;


int main(int argc, char **argv) {	
	Board* b = argc == 3 ? new FissionBoard(argv[1], argv[2]) : new FissionBoard();
  	
  	std::cout << *b;
  	while (!b->gameOver() && std::cin) {
		std::cout << "PLAYER " << b->getCurrentPlayer() << std::endl;
		std::string move;
		if (std::getline(std::cin, move)) {
			std::istringstream in(move);
			int fromR, fromC, toR, toC;
			if (in >> fromR >> fromC >> toR >> toC) {
				if (b->isLegalMove(fromR, fromC, toR, toC)) {
					b->makeMove(fromR, fromC, toR, toC);
					std::cout << *b;
				}
				else {
					std::cout << "illegal move" << std::endl;
				}
			}
			else {
				std::cout << "invalid input" << std::endl;
			}
		}
	}
	if (b->gameOver()) {
		if ((dynamic_cast<FissionBoard*>(b))->isDraw())
			std::cout << "Draw" << std::endl;
		else
			std::cout << (b->getCurrentPlayer() + 1) % 2 << " wins" << std::endl;
	}
	
	delete b;
}