#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

#include "fissionboard.h"
#include "fissionpiece.h"
#include "fissionpiecelight.h"

#include "math.h"

namespace cs427_527 {
	FissionBoard::FissionBoard() : FissionBoard(8, 8) {}

	FissionBoard::FissionBoard(char* ws, char* hs) {
		int w = 0, h = 0;
		std::istringstream issw(ws);
		issw >> w;
		std::istringstream issh(hs);
		issh >> h;
		if (w & 1 || h & 1 || w < h || h < 4 || w < 4) {
			//std::cout << "wrong board configure\n";
			new (this) FissionBoard();
		}
		else 
			new (this) FissionBoard(w, h);
	}

	FissionBoard::FissionBoard(int w, int h) : Board(w, h, 0) {
		bool color = 0;
		int lim = 1;
		
		/* upper */
		for (int r = height/2-1; r >= 1; -- r) {
			int rowcolor_l = (int)color, rowcolor_r = (int)(!color);
			for (int c = width/2-1; c >= lim; -- c) {
				if ((h == 6 && c > 1 && c < w-2) || (h > 6 && (c == 2 || c == w-3)))
					board[r][c] = std::make_shared<FissionPieceLight>(rowcolor_l, r, c);
				else 
					board[r][c] = std::make_shared<FissionPiece>(rowcolor_l, r, c);
				rowcolor_l  = (rowcolor_l+1) & 1;
			}
			for (int c = width/2; c < width-lim; ++ c) {
				if ((h == 6 && c > 1 && c < w-2) || (h > 6 && (c == 2 || c == w-3)))
					board[r][c] = std::make_shared<FissionPieceLight>(rowcolor_r, r, c);
				else
					board[r][c] = std::make_shared<FissionPiece>(rowcolor_r, r, c);
				rowcolor_r  = (rowcolor_r+1) & 1;
			}
			color = !color;
			lim ++;
		}
		
		/* lower */
		color = 1;
		lim = 1;
		for (int r = height/2; r < height-1; ++ r) {
			int rowcolor_l = (int)color, rowcolor_r = (int)(!color);
			for (int c = width/2-1; c >= lim; -- c) {
				if ((h == 6 && c > 1 && c < w-2) || (h > 6 && (c == 2 || c == w-3)))
					board[r][c] = std::make_shared<FissionPieceLight>(rowcolor_l, r, c);
				else 
					board[r][c] = std::make_shared<FissionPiece>(rowcolor_l, r, c);
				rowcolor_l = (rowcolor_l+1) & 1;
			}
			for (int c = width/2; c < width-lim; ++ c) {
				if ((h == 6 && c > 1 && c < w-2) || (h > 6 && (c == 2 || c == w-3)))
					board[r][c] = std::make_shared<FissionPieceLight>(rowcolor_r, r, c);
				else 
					board[r][c] = std::make_shared<FissionPiece>(rowcolor_r, r, c);
				rowcolor_r = (rowcolor_r+1) & 1;
			}
			color = !color;
			lim ++;
		}
	}

	FissionBoard::~FissionBoard() {}

	int 
	FissionBoard::getBoardColor(int row, int col) const {
		if (row % 2 == col % 2) {
			return Color::WHITE;
		}
		else {
			return Color::BLACK;
		}
	}

	bool 
	FissionBoard::isLegalMove(int fromR, int fromC, int toR, int toC) const {
		if (!inBounds(fromR, fromC) || !inBounds(toR, toC) || (fromR == toR && fromC == toC)) {
			//std::cout << "board boundary\n";
			return false;
		}
		
		std::shared_ptr<const Piece> move_from = getPiece(fromR, fromC);
		if (getPiece(toR, toC) != nullptr || move_from == nullptr) {
			//std::cout << "board empty or nonempty\n";
			return false;
		}
		if (toR != fromR && toC != fromC && iabs(toR-fromR) != iabs(toC-fromC)) {
			//std::cout << "board cannot form a line \n";
			return false;
		}
		
		if (move_from->getPlayer() != turn) {
			//std::cout << "board turn error \n";
			return false;
		}

		return move_from->isLegalMove(*this, toR, toC);
	}

	void 
	FissionBoard::makeMove(int fromR, int fromC, int toR, int toC) {
		if (isLegalMove(fromR, fromC, toR, toC)) {
			std::shared_ptr<Piece> move_from = getPiece(fromR, fromC);
			move_from->makeMove(*this, toR, toC);
			turn = (turn + 1) % 2;
		}
	}

	bool 
	FissionBoard::gameOver() const {
		for (int i = 0; i < height; ++ i) {
			for (int j = 0; j < width; ++ j)
				if (getPiece(i,j) != nullptr && getPiece(i,j)->getPlayer() == turn)
					return false;
		}
		return true;
	}

	bool
	FissionBoard::isDraw() const{
		for (int i = 0; i < height; ++ i) {
			for (int j = 0; j < width; ++ j)
				if (getPiece(i,j) != nullptr)
					return false;
		}
		return true;
	}

	std::string 
	FissionBoard::toString() const {
		std::ostringstream os;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				if (getPiece(r, c) == nullptr) {
					if (getBoardColor(r, c) == Color::WHITE) {
						os << "..";
					}
					else {
					os << "  ";
					}
				}
				else {
					os << getPiece(r, c)->toString();
				}
			}
			os << std::endl;
		}
		/* HTML part */
		toHTML();

		return os.str();
	}

	void
	FissionBoard::toHTML() const {
		std::ofstream myfile;
		myfile.open ("fission_output.html");

		myfile << "<!DOCTYPE html>\n<html>\n<head>\n"
			<< "<meta charset=\"UTF-8\">\n"
			<< "<title>Fission</title>\n</head>\n<body>\n"
			<< "<canvas id=\"board\" width=\"" << std::to_string(width*20) 
			<< "\" height=\"" << std::to_string(height*20) << "\"></canvas>\n"
			<< "<script>\n"
			<< "var canvas = document.getElementById('board');\n"
			<< "var g = canvas.getContext('2d');\n";

		/* fill in board */
		for (int i = 0; i < height; ++ i) {
			for (int j = 0; j < width; ++ j){
				std::string boardColor = getBoardColor(i, j) == Color::WHITE ? "g.fillStyle = '#FFFFFF';\n":"g.fillStyle = '#808080';\n";
				std::string boardShape = "g.fillRect(" + std::to_string(j*20) + ", " + std::to_string(i*20) + ", 20, 20);\n";
				myfile << boardColor << boardShape;
			}
		}

		/* fill in piee */
		for (int i = 0; i < height; ++ i) {
			for (int j = 0; j < width; ++ j){
				if (getPiece(i,j) != nullptr) {
					myfile << std::dynamic_pointer_cast<FissionPiece>(board[i][j])->toHTML();
				}
			}
		}

		//ending html
		myfile << "</script>\n</body>\n</html>\n";
    myfile.close();
	}
}