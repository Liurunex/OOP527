#include "conway.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib> 

using cs427_527::PuzzleMove;
using cs427_527::Conway;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::strcpy;
using std::pair;
using std::getline;
using std::ostream;
using std::istream;
using std::istringstream;
using std::vector;

Conway::Conway(): rowSize(5), colSize(6), solved(false), moves(0) {
	board = new char*[rowSize];
	for (int i = 0; i < rowSize; ++ i)
		board[i] = new char[colSize];
	
	for (int i = 0; i < rowSize; ++ i)
		for (int j = 0; j < colSize; ++ j)
			board[i][j] = '.';

	board[rowSize/2][1]   = 'X';
	board[rowSize/2][2]   = 'X';
	board[rowSize/2][3]   = 'X';
	board[rowSize/2+1][3] = 'X';
}

Conway::Conway(istream& instream): solved(false), moves(0) {
	string lines;
	int linecounter = 0;
	while (getline(instream, lines)) {
		if (!linecounter) {
			istringstream iss(lines);
			vector<int> parameters;
			int varsize = 0;
			while (iss >> varsize){
				if (varsize <= 0) {
					throw "illegal input";
				}
				parameters.push_back(varsize);
			}
			if (parameters.size() != 2) {
				throw "illegal input";
			}

			colSize = parameters[0];
			rowSize = parameters[1];
			
			board = new char*[rowSize];
			for (int i = 0; i < rowSize; ++ i)
				board[i] = new char[colSize];
			linecounter ++;
			continue;
		}
		if (linecounter > rowSize || lines.length() != (size_t)colSize || 
			lines.find_first_not_of("X.") != string::npos)
			throw "illegal input";
		
		strcpy(board[linecounter-1], lines.c_str());
		linecounter ++;
	}
	if (linecounter != rowSize+1) {
		throw "illegal input";
	}
}

/* copy constructor */
Conway::Conway(const Conway& a) {
	rowSize = a.rowSize;
	colSize = a.colSize;
	solved  = a.solved;
	moves   = a.moves;

	board   = new char*[rowSize];
	for (int i = 0; i < rowSize; ++ i) {
		board[i] = new char[colSize];
		strcpy(board[i], a.board[i]);
	}
}

/* move constructor */
Conway::Conway(Conway&& a) {
	rowSize   = a.rowSize;
	colSize   = a.colSize;
	solved    = a.solved;
	moves     = a.moves;
	board     = a.board;

	a.board   = nullptr;
	a.rowSize = 0;
	a.colSize = 0;
	a.solved  = false;
	a.moves   = 0;
}

/* assignment operator */
Conway&
Conway::operator=(const Conway& a) {
	if (&a == this)
		return *this;

	for (int i = 0; i < rowSize; ++ i)
		delete board[i];
	delete[] board;

	rowSize = a.rowSize;
	colSize = a.colSize;
	solved  = a.solved;
	moves   = a.moves;

	board   = new char*[rowSize];
	for (int i = 0; i < rowSize; ++ i) {
		board[i] = new char[colSize];
		strcpy(board[i], a.board[i]);
	}

	return *this;
}

/* move assignment operator */
Conway&
Conway::operator=(Conway&& a) {
	if (&a == this)
		return *this;
	
	for (int i = 0; i < rowSize; ++ i)
		delete board[i];
	delete[] board;

	rowSize = a.rowSize;
	colSize = a.colSize;
	solved  = a.solved;
	moves   = a.moves;
	board   = a.board;
	
	a.board   = nullptr;
	a.rowSize = 0;
	a.colSize = 0;
	a.solved  = false;
	a.moves   = 0;

	return *this;
}

Conway::~Conway() {
	for (int i = 0; i < rowSize; ++ i)
		delete board[i];
	delete[] board;
}

bool 
Conway::isLegalMove(PuzzleMove* move) const {
	if (move->getType() != "conway") 
		throw "illeagal move parameters";
	int fromR = move->access(0), fromC = move->access(1), 
		toR = move->access(2), toC = move->access(3);
	
	if (fromR < 0 || fromR >= rowSize || fromC < 0 || fromC >= colSize ||
		toR < 0 || toR >= rowSize || toC < 0 || toC >= colSize ||
		board[fromR][fromC] != 'X' || board[toR][toC] != '.')
		return false;
	
	if((!(fromR-toR) && (abs(fromC-toC) == 2) && board[fromR][(fromC+toC)/2] == 'X') ||
		(!(fromC-toC) && (abs(fromR-toR) == 2) && board[(fromR+toR)/2][fromC] == 'X'))
		return true;
	return false;
}

void 
Conway::makeMove(PuzzleMove* move) {
	if (move->getType() != "conway") 
		throw "illeagal move parameters";
	int fromR = move->access(0), fromC = move->access(1), 
		toR = move->access(2), toC = move->access(3);
	
	if (isLegalMove(move)) {
		board[fromR][fromC] = '.';
		board[toR][toC] = 'X';
		if (!(fromR-toR)) board[fromR][(fromC+toC)/2] = '.';
		else board[(fromR+toR)/2][fromC] = '.';
		this->moves ++;
	}
	else throw "illegal move";
}

bool
Conway::isSolved() const {
	for (int i = 0; i <= colSize; ++ i)
		if (board[0][i] == 'X')
			return true;
	return false;
}

int 
Conway::totalMoves() const {
	return this->moves;
}

string 
Conway::toString() const{
	string output;
	for (int i = 0; i < rowSize; ++ i){
		for (int j = 0; j < colSize; ++ j)
			output += board[i][j];
		if (i != rowSize-1) output += '\n';
	}
	return output;
}


PuzzleMove* 
Conway::readMove(std::istream& movesIn) {
	PuzzleMove* move = new PuzzleMove();
	move->setType("conway");
	int pos;
	for (int i = 0; i < 4; ++ i){
		if (movesIn >> pos)
			move->addItem(pos);
		else {
			delete move;
			return nullptr;
		}
	}
	return move;
}
