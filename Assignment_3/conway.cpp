#include "Conway.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib> 

using cs427_527::Conway;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::strcpy;
using std::pair;

Conway::Conway() : rowSize(5), colSize(6), solved(false) {
	board = new char*[rowSize];
	for (size_t i = 0; i < rowSize; ++ i)
		board = new char[colSize];
	for (size_t i = 0; i < rowSize; ++ i)
		for (size_t j = 0; j < COL; ++ j)
			board[i][j] = '.';

	board[rowSize/2][0]   = 'X';
	board[rowSize/2][1]   = 'X';
	board[rowSize/2][2]   = 'X';
	board[rowSize/2+1][2] = 'X';

}

Conway::Conway(const string& s) {
}

/* copy constructor */
Conway(const Conway& a) {
	int row = a.boardSize().first;
	int col = a.boardSize().second;
	board  = new char*[row];
	for (size_t i = 0; i < row; ++ i) {
		board[i] = new char[col];
		strcpy(board[i], a.board[i]);
	}
}

/* move constructor */
Conway(Conway&& a) {
	board = a.board;
	a = nullptr;
}

/* assignment operator */
Conway& operator=(const Conway& a) {
	if (&a == this)
		return *this;

	int row = a.boardSize().first;
	int col = a.boardSize().second;
	for (size_t i = 0; i < row; ++ i)
		delete board[i];
	delete[] board;

	board  = new char*[row];
	for (size_t i = 0; i < row; ++ i) {
		board[i] = new char[col];
		strcpy(board[i], a.board[i]);
	}

	return *this
}

/* move assignment operator */
Conway& operator=(Conway&& a) {
	if (&a == this)
		return *this;
	
	int row = a.boardSize().first;
	for (size_t i = 0; i < row; ++ i)
		delete board[i];
	delete[] board;

	board = a.board;
	a.board = nullptr;

	return *this;
}

Conway::~Conway() {
	for (size_t i = 0; i < rowSize; ++ i)
		delete board[i];
	delete[] board;
}

bool 
Conway::isLegalMove(int fromR, int fromC, int toR, int toC) const {}

void 
Conway::makeMove(int fromR, int fromC, int toR, int toC) {}

int 
Conway::totalMoves() const {
	return moves.size();
}

bool
Conway::isSolved() const {}

void
Conway::interactive_mode() {}

void 
Conway::non_interactive_mode(int& start_position, int& argc, char** argv) {}

string 
Conway::toString() {
	string output;
	for (size_t i = 0; i < rowSize; ++ i)
		for (size_t j = 0; j < colSize; ++ j)
			output += board[i][j];
	return output;
}

pair<int, int> 
Conway::boardSize() {
	return {rowSize, colSize};
}

namespace cs427_527 {
	ostream& operator<<(ostream& out, const Conway& a) {
		return out << a.toString();
	}
}
