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
         * fucntion description:
         *
         */
        SpinOut();
        
        /* the override constructor with board setting: 
         * parameters description:
         *
         * fucntion/return description:
         * 
         */
        SpinOut(const std::string& s);
        
        /* the default destructor 
         * no parameters;
         * fucntion description:
         *
         */
        ~SpinOut();

        /* interactive mode 
         * parameters description:
         * fucntion/return description:
         * 
         */
        void interactive_mode();
        
        /* non-interactive mode 
         * parameters description:
         * fucntion/return description:
         * 
         */
        void non_interactive_mode(int& start_position,
            int& argc, char** argv);
    
    private:
        bool isLegalMove(int i) const;
        void makeMove(int i);
        int totalMoves() const;
        bool isSolved() const;
        void boardPrint() const;
        std::string toString() const;

        static const int SIZE = BOARD_SIZE;
        std::vector<int> moves;
        char board[BOARD_SIZE];
    };
}
    
#endif
