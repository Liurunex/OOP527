#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <string>
#include <vector>
#define BOARD_SIZE 7

namespace HW {
    class SpinOut {
    public:
        SpinOut();
        SpinOut(const std::string& s);
        ~SpinOut();

        void interactove_mode();
        void non_interactove_mode(int& start_position,
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
