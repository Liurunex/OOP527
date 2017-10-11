#ifndef __CONWAY_H__
#define __CONWAY_H__

#include <string>
#include <vector>
#include <iostream>

namespace cs427_527 {
	class Conway {
	public:
		Conway();

		Conway(std::istream& instream);

		/* copy constructor */
		Conway(const Conway& a);
		
		/* move constructor */
		Conway(Conway&& a);

		/* assignment operator */
		Conway& operator=(const Conway& a);

		/* move assignment operator */
		Conway& operator=(Conway&& a);

		~Conway();

		void interactive_mode();

		void non_interactive_mode(int& start_position,
		int& argc, char** argv);

		bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

		void makeMove(int fromR, int fromC, int toR, int toC);

		int totalMoves() const;

		bool isSolved() const;

		std::string toString() const;

		std::pair<int, int> boardSize() const;

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
