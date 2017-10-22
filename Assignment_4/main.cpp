#include "cooccur.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using std::string;
using std::filebuf;
using std::istream;

int main (int argc, char** argv) {
	std::vector<string> keywords;
	for (int i = 1; i < argc; ++ i) {
		string elem(argv[i]);
		keywords.push_back(elem);
	}

	CooccurrenceMatrix<string> ccMatrixObejct(keywords);
	ccMatrixObejct.worker(std::cin, keywords);

    return 0;
}