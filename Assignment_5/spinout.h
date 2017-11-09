#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <string>
#include <vector>
#include <iostream>
#include "puzzle.h"

namespace cs427_527 {
    class SpinOut : public Puzzle {
    public:
        /* the default constructor 
        * no parameters;
        * initial the board on default setting
        */
        SpinOut();

        /* the override constructor with board setting: 
        * parameters: a 7-character string only consisted of '/' and '-';
        * fucntion: initial the board based on user input, once detecting the user input was
        * invalid, then initial the board with default setting
        */
        SpinOut(const std::string& s);
        
        /* the default destructor 
         * no parameters;
         * fucntion: destruct the class members
         */
        ~SpinOut();

        /* parameter: input stream;
         * fucntion: read move positions from stream, construct the PuzzleMove obejct
         * and return its pointer
         */
        PuzzleMove* readMove(std::istream& movesIn);

        /* parameter: a PuzzleMove pointer which stores the index of the indicated disk;
         * fucntion: take an move pointer, extracted the position, 
         * judge if it was between 0 and 6 inclusive,
         * then determine whether it is possible to rotate that disk in the current 
         * object to its other orientation. Disks are numbered from left to right 
         * starting with zero.
         */
        bool isLegalMove(PuzzleMove* move) const;

        /* parameter: a PuzzleMove pointer which stores the index of the indicated disk;
         * fucntion: it first call isLegaMove to determine if the index is valid; 
         * thenrotate the indicated disk in the current object 
         * into its other orientation, provided that such a move is legal.
         */
        void makeMove(PuzzleMove* move);

        /* no parameter;
         * fucntion: determines if the current object is in 
         * its solved configuration (all disks rotated horizontally).
         */
        bool isSolved() const;

        /* no parameter;
         * fucntion: count the number of legal moves performed on 
         * the current object since it was created.
         */
        int totalMoves() const;

        /* no parameter;
         * fucntion: return a string representation of 
         * the current object in the same format as that 
         * passed to the second version of the constructor.
         */
        std::string toString() const; 

        static const int SIZE = 7;    
    
    private:    
        void boardPrint() const;
        bool solved = false;
        std::vector<int> moves;
        //std::string board;
        char board[SIZE];
    };
}
    
#endif
