#ifndef __PUZZLE_MOVE_H__
#define __PUZZLE_MOVE_H__

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

namespace cs427_527 {
	class PuzzleMove {
	public:

		PuzzleMove() {}

		~PuzzleMove() {}

		void addItem(int& i) { elements.push_back(i); }

		int access(int index) const { 
			return index < (int)elements.size() ? elements[index]:0; }

		void setType(std::string setstr) { type = setstr; }

		std::string getType() const { return type; }

		std::string toString() const {
			std::stringstream ss;
			std::copy( elements.begin(), elements.end(), std::ostream_iterator<int>(ss, " "));
			std::string s = ss.str();
			s = s.substr(0, s.length()-1);
			return s;
		}

		friend std::ostream& operator<<(std::ostream& out, const PuzzleMove& a) {
			return out << a.toString();
		}
	private:
		std::vector<int> elements;
		std::string type;
	};
	

}

#endif
