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

SpinOut::SpinOut() {
	memset(board, '/', sizeof(board));
}

SpinOut::SpinOut(const string& s) {
	if (s.length() != SIZE || 
		s.find_first_not_of("-/") != string::npos) {
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
	cout << toString() << endl;
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
	else throw "illegal move";
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

string 
SpinOut::toString() const {
	string return_res(board);
	return return_res;
}

void
SpinOut::interactive_mode() {
	this->boardPrint();
	if (this->isSolved()) {
		cout << this->totalMoves() << " moves\n";
		return;
	}
	do {
		if (this->solved) {
			cout << this->totalMoves() << " moves\n";
			return;
		}

		int index = -1;
		try {
			if (cin >> index) {
				this->makeMove(index);
				this->boardPrint();
			}
			else {
				//cout << "whoops: you gived it up :)\n";
				return;
			}	
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	} while ((!this->isSolved()) || (this->solved = true));
}

void 
SpinOut::non_interactive_mode(int& start_position, int& argc,
	char** argv) {
	int index = start_position;
	if (this->isSolved()) {
		cout << " SOLVED\n";
		return;
	}
	do {
		if (this->solved) {
			cout << "SOLVED\n";
			return;
		}
		if (index >= argc) break;
		string candiate_move(argv[index]);
		if (candiate_move.length() == 1 && isdigit(candiate_move[0])) {
			int rotate_pos = stoi(candiate_move); 
			try { 
				makeMove(rotate_pos); 
			}
			catch (const char* msg) {
				cout << "SpinOut: illegal move " << rotate_pos << " in position "
				<< index << " for " << toString() << endl;
				return;
			}
			index ++;
		}
		else {
			//cout << "Error: invalid move input\n";
			return;
		}
	} while ((!this->isSolved()) || (this->solved = true));
	this->boardPrint();
}
