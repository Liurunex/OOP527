#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <string>

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
        static const int SIZE = 7;
        int user_move = 0;
        char board[7];
    };
}
    
#endif
