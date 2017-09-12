#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <string>
#define BOARD_SIZE 7
    

namespace HW {
    class SpinOut {
    public:
        SpinOut();
        SpinOut(const std::string& s);
        ~SpinOut();

        bool isLegalMove(int i) const;
        void makeMove(int i);
        int totalMoves() const;
        bool isSolved() const;
        void boardPrint() const;
        std::string toString() const;
        
    private:
        static const int SIZE = BOARD_SIZE;
        int user_move;
        char board[BOARD_SIZE];
    };
}
    
#endif
