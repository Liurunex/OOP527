#ifndef __CONWAY_H__
#define __CONWAY_H__

#include <string>
#include <vector>
#include <iostream>

namespace cs427_527 {
	class Conway {
	public:
		/* the default constructor 
         * no parameters;
         * initial the board on default setting
         */
		Conway();

		/* the override constructor with board setting: 
         * parameters: input stream
         * fucntion: create a puzzle whose initial state is read from the given stream.
         */
		Conway(std::istream& instream);

		/* copy constructor 
         * parameter: reference of a puzzle game object 
         * fucntion: creates an independent copy of the given puzzle state 
         * (changes to the new copy shouldn't affect the original).
		 */
		Conway(const Conway& a);
		
		/* move constructor 
		 * parameter: right value reference of a game object
  		 * function copy the given puzzle state's representation and leaves 
  		 * that puzzle in a valid (destructable) state
		 */
		Conway(Conway&& a);

		/* assignment operator 
		 * parameter: reference of a puzzle game object 
		 * fucntion: makes the puzzle on the left of the assignment operator an independent 
		 * copy of the puzzle on the right and returns a reference.
 		 */
		Conway& operator=(const Conway& a);

		/* move assignment operator 
		 * parameter:right value reference of a game object
		 * fucntion: copy state of the puzzle on the right of the assignment operator 
		 * into the puzzle on the left, leaving the puzzle on the right in a valid 
		 * (destructable) state, and returns a reference to the puzzle on the left.
		 */
		Conway& operator=(Conway&& a);

		/* the default destructor 
         * no parameters;
         * fucntion: destruct the class members
         */
		~Conway();

		/* interactive mode 
         * no parameters
         * fucntion: it will first print the board and check if the puzzle has bee solved,
         * then request the input from user; once it got valid input from iostream, it calls 
         * the makeMove function to do the jump. the fucntion will keep repeating the
         * process unitl the puzzle is solved or the input is unvalid or empty which indicates
         * the user give it up.
         */
		void interactive_mode();

		/* non-interactive mode 
         * parameter: a integer called start_position records the start index of jump 
         * operation; a integer argc records the arguments number, and a char** argv 
         * stores all the input arguments.
         * fucntion: it starts from the start_postion to do the jump operation, determine 
         * whether current jump position was valid; if so do the normal jump operation, 
         * otherwise terminate the running game.
         */
		void non_interactive_mode(int& start_position,
		int& argc, char** argv);

		/* parameter: four integers representing position;
         * fucntion: take integers representing the row and column of the position 
         * on the board to move from and to move to and determines whether such a move
         * is legal according to the rules of the puzzle. If either of the positions
         * is not on the board then the move is illegal.
         */
		bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

		/* parameter: four integers representing position;
         * fucntion: take a legal move represented by integers giving the row and 
         * column of the position on the board to move from and to move to and modifies 
         * the current object to reflect the result of that move.
         */
		void makeMove(int fromR, int fromC, int toR, int toC);

		/* no parameter;
         * fucntion: count the number of legal moves performed since the initial 
         * state of the original object
         */
		int totalMoves() const;

		/* no parameter;
         * fucntion: determines determines if the current object is in its 
         * solved configuration (some piece in the top row)
         */
		bool isSolved() const;

		/* no parameter;
         * fucntion: return a string representation of 
         * the game board configuration
         */
		std::string toString() const;

	private:    
		int rowSize = 5;
		int colSize = 6;
		bool solved = false;
		int moves   = 0;
		char** board;
	};

	std::ostream& operator<<(std::ostream& out, const Conway& a);
}

#endif
