#include <memory>

#include "fissionboard.h"
#include "fissionpiece.h"

#include "math.h"

#include <vector>
#include <utility> 

namespace cs427_527 {
	FissionPiece::FissionPiece(int p, int r, int c) : Piece(p, r, c) {}

	FissionPiece::~FissionPiece() {}

	bool 
	FissionPiece::isLegalMove(const Board& board, int toR, int toC) const {
		//todo: change movement as slide to
		int unitR = 0, unitC = 0;
		int isDown = toR-this->row, isRight = toC-this->col;
		
		if (this->row == toR) {
			unitC = isRight > 0 ? 1:-1;
		}
		else if (this->col == toC) {
			unitR = isDown > 0 ? 1:-1;
		}
		else {
			unitR = isDown > 0 ? 1:-1; 
			unitC = isRight > 0 ? 1:-1;
		}

		int moveRow = this->row+unitR, moveCol = this->col+unitC;
		while (moveRow != toR || moveCol != toC) {
			if (board.getPiece(moveRow, moveCol) != nullptr) {
				//std::cout << "piece line contains interval node";
				return false;
			}
			moveRow += unitR;
			moveCol += unitC;
		}

		/* one more check */
		moveRow += unitR;
		moveCol += unitC;
		if (!board.inBounds(moveRow, moveCol) || board.getPiece(moveRow, moveCol) != nullptr)
			return true;
		
		//std::cout << "piece next check failed";
		return false;
	}

	void 
	FissionPiece::makeMove(Board& board, int toR, int toC) {
		if (isLegalMove(board, toR, toC)) {
			std::shared_ptr<Piece> self = board.getPiece(row, col);

			int unitR = 0, unitC = 0;
			int isDown = toR-this->row, isRight = toC-this->col;
			
			if (this->row == toR) {
				unitC = isRight > 0 ? 1:-1;
			}
			else if (this->col == toC) {
				unitR = isDown > 0 ? 1:-1;
			}
			else {
				unitR = isDown > 0 ? 1:-1; 
				unitC = isRight > 0 ? 1:-1;
			}

			board.removePiece(row, col);
			row = toR;
			col = toC;
			board.placePiece(toR, toC, self);

			int hitR = row+unitR, hitC = col+unitC;
			if (board.inBounds(hitR, hitC)) {
				std::shared_ptr<FissionPiece> hstone = std::dynamic_pointer_cast<FissionPiece>(board.getPiece(hitR, hitC));
				
				if (hstone != nullptr)
					hstone->hitRemove(board, row, col);
			} 
		}
	}

	void
	FissionPiece::hitRemove(Board& board, int hitR, int hitC) {

		board.removePiece(hitR, hitC);
		std::vector<std::pair<int, int>> direcs = {{-1,0},{1,0},{0,1},{0,-1},
			{1,1},{-1,1},{1,-1},{-1,-1}};
		for (auto direc:direcs) {
			int remove_row = hitR+direc.first, remove_col = hitC+direc.second;
			if (remove_row == row && remove_col == col)
				continue;
			if (board.inBounds(remove_row, remove_col)) {
				std::shared_ptr<Piece> rstone = board.getPiece(remove_row, remove_col);
				if (rstone == nullptr) 
					continue;
				board.removePiece(remove_row, remove_col);
			}
		}
		board.removePiece(row, col);
	}

	std::string 
	FissionPiece::toString() const {
		return (player == 0 ? "RR" : "BB");
	}

	std::string
	FissionPiece::toHTML() const {
		std::string pieceColor = player == 0 ? "g.fillStyle = '#FF0000';\n":"g.fillStyle = '#0000FF';\n";
		std::string pieceShape = "g.arc(" + std::to_string(col*20+10) + ", " + std::to_string(row*20+10) + 
			", 8, 0, 2*Math.PI);\n";
		return "g.beginPath();\n" + pieceShape + pieceColor + "g.fill();\n";
	}
}