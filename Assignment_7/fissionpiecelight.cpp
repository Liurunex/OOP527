#include <algorithm>
#include <cctype>

#include "fissionpiecelight.h"
#include "fissionboard.h"

namespace cs427_527 {
	FissionPieceLight::FissionPieceLight(int p, int r, int c) : FissionPiece(p, r, c) {}

	FissionPieceLight::~FissionPieceLight() {}

	std::string 
	FissionPieceLight::toString() const {
		return (player == 0 ? "rr" : "bb");
	}

	void 
	FissionPieceLight::hitRemove (Board& board, int hitR, int hitC) {
		board.removePiece(hitR, hitC);
		board.removePiece(row, col);
	}

	std::string
	FissionPieceLight::toHTML() const {
		std::string pieceColor = player == 0 ? "g.fillStyle = '#FF0000';\n":"g.fillStyle = '#0000FF';\n";
		std::string pieceShape = "g.arc(" + std::to_string(col*20+10) + ", " + std::to_string(row*20+10) + 
			", 5, 0, 2*Math.PI);\n";
		return "g.beginPath();\n" + pieceShape + pieceColor + "g.fill();\n";
	}
}