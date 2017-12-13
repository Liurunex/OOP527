#ifndef __FISSIONPIECELIGHT_H__
#define __FISSIONPIECELIGHT_H__

#include <string>
#include "fissionpiece.h"

namespace cs427_527 {
	class FissionBoard;
	
	class FissionPieceLight : public FissionPiece{
	public:
		/* the constructor to accept two valid inputs to 
		 * construct the board
		 */
		FissionPieceLight(int p, int r, int c);
		
		/* the default destructor */
		~FissionPieceLight();
		
		/**
		* Returns a printable representation of this checker.
		*
		* @return a printable representation of this checker
		*/
		std::string toString() const override;
		
		/**
	     * Returns a HTML representation of this piece.
	     *
	     * @return a HTML representation of this piece.
	     */
		std::string toHTML() const override;

	protected:
		void hitRemove (Board& board, int hitR, int hitC) override;
	};
}

#endif