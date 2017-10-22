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
	for (int i = 1; i < argc-2; ++ i) {
		string elem(argv[i]);
		keywords.push_back(elem);
	}

	string inputfile(argv[argc-1]);
	try {
		filebuf fb;
		if (fb.open(inputfile, std::ios::in)) {
			istream binfo(&fb);
			
			CooccurrenceMatrix<string> ccMatrixObejct(keywords);
			ccMatrixObejct.worker(binfo);
			
			fb.close();
		}
		else return 1;
	}
	catch (const char* msg) {
		//std::cout << msg << std::endl;
		return 1;
	}

    return 0;
}