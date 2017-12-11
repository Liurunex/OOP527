#include "piece.h"

namespace cs427_527 {
	
	Piece::Piece(int p, int r, int c): player(p), row(r), col(c) {}

	Piece::~Piece() {}

	int Piece::getPlayer() const { return player; }
}

