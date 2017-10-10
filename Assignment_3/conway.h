#ifndef __CONWAY_H__
#define __CONWAY_H__

#include <string>
#include <vector>

namespace cs427_527 {
	class Conway {
	public:
		Conway();

		Conway(istream&);

		/* copy constructor */
		Conway(const Conway&);
		
		/* move constructor */
		Conway(Conway&&);

		/* assignment operator */
		Conway& operator=(const Conway&);

		/* move assignment operator */
		Conway& operator=(Conway&&);

		~Conway();

		void interactive_mode();

		void non_interactive_mode(int& start_position,
		int& argc, char** argv);

		bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

		void makeMove(int fromR, int fromC, int toR, int toC);

		int totalMoves() const;

		bool isSolved() const;

		std::string toString();

		std::pair<int, int> boardSize();

	private:    
		int rowSize;
		int colSize;
		bool solved;
		std::vector<int> moves;
		char** board;
	};

	std::ostream& operator<<(ostream& out, const Conway& a);
}

#endif
