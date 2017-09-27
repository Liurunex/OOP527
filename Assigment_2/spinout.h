#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <string>
#include <vector>

#define BOARD_SIZE 7

namespace cs427_527 {
    class SpinOut {
    public:
        /* the default constructor 
         * no parameters;
         * initial the board on default setting
         */
        SpinOut();
        
        /* the override constructor with board setting: 
         * parameters: a 7-character string only consisted of '/' and '-';
         * fucntion: initial the board based on user input, if the user input was
         * invalid, then initial the board with default setting
         */
        SpinOut(const std::string& s);
        
        /* the default destructor 
         * no parameters;
         * fucntion: destruct the class members
         */
        ~SpinOut();

        /* interactive mode 
         * no parameters
         * fucntion: it will first print the board and check if the puzzle has bee solved,
         * then request the input from user; once it gets a integer from iostream, it calls 
         * the makeMove function to do the rotation. the fucntion will keep repeating the
         * process unitl the puzzle is solved or the input is any non-digit which indicates
         * the user give it up.
         */
        void interactive_mode();
        
        /* non-interactive mode 
         * parameter
         * fucntion: 
         * 
         */
        void non_interactive_mode(int& start_position,
            int& argc, char** argv);
        
        /* parameter: a integer which is the index of the indicated disk ;
         * fucntion: take an integer to judge if it was between 0 and 6 inclusive,
         * then determine whether it is possible to rotate that disk in the current 
         * object to its other orientation. Disks are numbered from left to right 
         * starting with zero.
         */
        bool isLegalMove(int i) const;
        
        /* parameter: a integer which is the index of the indicated disk 
         * fucntion: it first call isLegaMove to determine if the index is valid; 
         * thenrotate the indicated disk in the current object 
         * into its other orientation, provided that such a move is legal.
         */
        void makeMove(int i);
        
        /* no parameter;
         * fucntion: count the number of legal moves performed on 
         * the current object since it was created.
         */
        int  totalMoves() const; 
        
        /* no parameter;
         * fucntion: determines if the current object is in 
         * its solved configuration (all disks rotated horizontally).
         */
        bool isSolved() const; 
        
        /* no parameter;
         * fucntion: return a string representation of 
         * the current object in the same format as that 
         * passed to the second version of the constructor.
         */
        std::string toString() const;   
        
        /* the static size value of the board, 
         * cannot be revised
         */
        static const int SIZE = 7;    
    
    private:    
        void boardPrint() const;
        bool solved = false;
        std::vector<int> moves;
        char board[SIZE];
    };
}
    
#endif
