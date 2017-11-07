#include "spinout.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib> 

using cs427_527::PuzzleMove;
using cs427_527::SpinOut;
using std::strcmp;
using std::string;
using std::endl;
using std::stoi;
using std::ostream;
using std::cout;
using std::cin;

SpinOut::SpinOut() {
	//board = "///////";
	memset(board, '/', sizeof(board));
}

SpinOut::SpinOut(const string& s) {
	if (s.length() != SIZE || 
		s.find_first_not_of("-/") != string::npos) {
		memset(board, '/', sizeof(board));
		//board = "///////";
	}
	else {
		for (size_t i = 0; i < s.length(); ++ i)
			this->board[i] = s.at(i);
	}
}

SpinOut::~SpinOut() {}

bool 
SpinOut::isLegalMove(PuzzleMove* move) const {
	if (move->getType() != "spinout") 
		throw "illeagal move parameters";
	int i = move->access(0);

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
SpinOut::makeMove(PuzzleMove* move) {
	if (move->getType() != "spinout") 
		throw "illeagal move parameters";
	int i = move->access(0);
	
	if (isLegalMove(move)) {
		board[i] = board[i] == '-' ? '/':'-';
		this->moves.push_back(i);
	}
	else throw "illegal move";
}

bool
SpinOut::isSolved() const {
	for (int i = 0; i < SIZE; ++ i)
		if (board[i] == '/')
			return false;
	return true;
}

int 
SpinOut::totalMoves() const {
	return moves.size();
}

string 
SpinOut::toString() const {
	//string return_res(board);
	string return_res;
	for (char it:board)
		return_res += it;
	return return_res;
}

PuzzleMove* 
SpinOut::readMove(std::istream& movesIn) {
	PuzzleMove* move = new PuzzleMove();
	move->setType("spinout");
	int pos;
	if (movesIn >> pos)
		move->addItem(pos);
	else {
		delete move;
		return nullptr;
	}

	return move;
}