#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <string>
#include <vector>
#include <iostream>
#include "puzzle.h"
#include "puzzle_move.h"

using cs427_527::PuzzleMove;

namespace cs427_527 {
    class SpinOut : public Puzzle {
    public:

        SpinOut();
        
        SpinOut(const std::string& s);
        
        ~SpinOut();

        PuzzleMove* readMove(std::istream& movesIn);

        bool isLegalMove(PuzzleMove* move) const;

        void makeMove(PuzzleMove* move);

        bool isSolved() const;

        int totalMoves() const;

        std::string toString() const; 

        static const int SIZE = 7;    
    
    private:    
        void boardPrint() const;
        bool solved = false;
        std::vector<int> moves;
        char board[SIZE];
    };

    std::ostream& operator<<(std::ostream& out, const SpinOut& a);
}
    
#endif
