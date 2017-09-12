#include <string>
#include "spinout.h"

namespace HW
{
	SpinOut::SpinOut()
	{}
	SpinOut::SpinOut(const std::string& s) 
	{}
	SpinOut::~SpinOut() 
	{}

	void SpinOut::boardPrint() const {
		for (int i = 0; i < SIZE; ++ i)
			cout << board[i];
		cout << "\n";
	}
	
	bool 
	SpinOut::isLegalMove(int i) const {
		if (i >= SIZE || i < 0) return false;
		if (i+1 == SIZE) return true;

		if (i+1 < SIZE && board[i+1] == '/')
			for (int j = i+2; j < SIZE; ++j)
				if (board[j] != '-'){
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
			cout << "Woops: illegal move." << endl;
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
	SpinOut::toString() const {}
    
}

int main (int argc, char** argv) {
	SpinOut* gameObejct = new SpinOut();
	gameObejct->boardPrint();
	
    return 0;
}