#ifndef __CHECKERBOARD_H__
#define __CHECKERBOARD_H__

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "board.h"

namespace cs427_527
{
  class Piece;

  class CheckerBoard : public Board
  {
  public:
    enum Color { BLACK, RED };

    /**
     * Creates a checkerboard with pieces in their initial locations.
     */
    CheckerBoard();

    /**
     * Destoys this board.
     */
    virtual ~CheckerBoard();
    
    /**
     * Returns the color of this board at the given position.
     *
     * @param row a row on this board
     * @param col a column on this board
     * @return the color of that position.
     */
    int getBoardColor(int row, int col) const;

    /**
     * Determines if it is legal to move a piece from the given
     * location to the given location on this board.
     *
     * @param fromR a row on this board
     * @param fromC a column on this board
     * @param toR a row on this board
     * @param toC a column on this board
     * @return true if and only if the move is legal
     */
    bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

    /**
     * Updates this move to reflect the effects of the given move.
     *
     * @param fromR the starting row of a legal move on this board
     * @param fromC the starting column of a legal move on this board
     * @param toR the ending row of a legal move on this board
     * @param toC the ending column of a legal move on this board
     */
    void makeMove(int fromR, int fromC, int toR, int toC);

    /**
     * Determines if the game on this board is over.
     *
     * @return true if and only if the game is over
     */
    bool gameOver() const;

    /**
     * Returns a printable representation of this board.
     *
     * @return a printable representation of this board
     */
    std::string toString() const;

  protected:
    /**
     * Returns the distance of the longest legal move on this board.
     *
     * @return the distance of the longest legal move
     */
    int findLongestMove() const;

    /**
     * Returns the distance of the longest legal move by the piece
     * at the given position on this board.
     *
     * @param fromR the row of a piece on this board
     * @param fromC the column of a piece on this board
     * @return the distance of the longest legal move for the piece
     * at that position
     */
    int findLongestMove(int fromR, int fromC) const;

    /**
     * A pointer to the piece that is in the middle of a sequence
     * of jumps.  This piece is the only one it is legal to move.
     * If there is no such piece, this is nullptr and it is legal
     * to move any piece that has a legal move.
     */
    std::shared_ptr<Piece> jumping;
  };

}
  
#endif

