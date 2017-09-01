#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <stdexcept> 

#define MILE_UNIT 3959
#define PI 3.141592654
using namespace std;

pair<int, double> formatConvert(string &input);

int main(int argc, char** argv) {
	double totalDistance = 0; 
	vector<double> location;
	string input;
	int read_index = 0;
	while (read_index < 4 && getline(cin, input)) {
		pair<int, double> inputRes = formatConvert(input);
		if (!inputRes.first) { cout << "Check your input, it's unvalid." << endl; continue; }
		location.push_back(inputRes.second);
		read_index ++;
		input.clear();
	}
	getline(cin, input);
	if (input.length()) cout << "Excessvie lines detected, check your input.";

	double col1     = (90-location[0])*PI/180;
	double col2     = (90-location[2])*PI/180;
	double diff_lon = (location[1]-location[3])*PI/180;

	cout << MILE_UNIT*acos(cos(col1)*cos(col2) + sin(col1)*sin(col2)*cos(diff_lon)) << endl;
	return 1;
}

pair<int, double> formatConvert(string &input) {
	pair<int, double> res = make_pair(1, 0.0);
	vector<double> format_record (3, 0);
	size_t sindex = 0; 
	for (size_t i = 0; i < 3; ++ i) {
		try {
			if (sindex >= input.size()) break;
			size_t sz_index = 0;
			format_record[i] = stod(&input[sindex], &sz_index);
			sindex += sz_index;
		}
		catch (const invalid_argument& info) {
			cerr << "Invalid argument: " << info.what() << '\n'; res.first = 0; return res;
		}
		catch (const out_of_range& info) {
			cerr << "Out of Range error: " << info.what() << '\n'; res.first = 0; return res;
		}
	}
	if (sindex != input.size() || format_record[1] < 0 || format_record[2] < 0) { 
		cerr << "Number is not valid" << '\n'; res.first = 0; return res; 
	}
	res.second = (format_record[0]<0 ? -1:1)* (fabs(format_record[0]) + format_record[1]/60 + format_record[2]/3600);
	return res;
}

/*
double + int unvalid
 */




