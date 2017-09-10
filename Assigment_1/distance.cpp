#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <stdexcept> 

#define MILE_UNIT 3959
using namespace std;

pair<int, double> formatConvert(string &input);
void error_print() { 
	cout << "Error: Unvalid Input. Standard input format: " << '\n' << 
	"Interger/Double or" << '\n' <<
	"Integer Double(positive) or"  << '\n' <<
	"Integer Integer(positive) Double(postive)" << endl; 
}
int main(int argc, char** argv) {
	double totalDistance = 0; 
	vector<double> location;
	string input;
	int read_index = 0;
	while (read_index < 4 && getline(cin, input)) {
		pair<int, double> inputRes = formatConvert(input);
		if (!inputRes.first) { 
			error_print();
			return 1; 
		}
		location.push_back(inputRes.second);
		read_index ++;
		input.clear();
	}
	/* check if the input contained exactly 4 lines */
	if (location.size() != 4) { cout << "Error: 4-line input is required" << endl; return 0; }
	getline(cin, input);
	if (input.length()) cout << "Warning: the program will ignore any excessive input line.\n";

	double col1     = (90-location[0])*M_PI/180;
	double col2     = (90-location[2])*M_PI/180;
	double diff_lon = (location[1]-location[3])*M_PI/180;

	totalDistance = MILE_UNIT*acos(cos(col1)*cos(col2) + sin(col1)*sin(col2)*cos(diff_lon)); 
	cout << totalDistance << endl;
	return 1;
}

pair<int, double> formatConvert(string &input) {
	pair<int, double> res = make_pair(1, 0.0);
	vector<double> format_record (3, 0);
	size_t sindex = 0; 
	for (size_t i = 0; i < 4; ++ i) {
		try {
			if (sindex >= input.size()) break;
			size_t sz_index = 0;
			string str = &input[sindex];
			if(str.find_first_not_of(' ') == string::npos ||
				str.find_first_not_of('\t') == string::npos) {
				cout << "Warning: please remove the space or '\t' at end of the line" << endl;
				break;
			}
			if (i == 3) {
				cout << "Warning: the program will ignore excessive elements in this line" << endl;
				break;
			}

			format_record[i] = stod(str, &sz_index);
			sindex += sz_index;
		}
		catch (const invalid_argument& info) {
			cout << "Error: Invalid argument in stod" << endl;
			res.first = 0; 
			if (i != 3) return res;
		}
		catch (const out_of_range& info) {
			cout << "Error: Out of Range error in stod " << endl; 
			res.first = 0; 
			if (i != 3) return res;
		}
	}
	int degree_check = floor(format_record[0]) == format_record[0],
		minute_check = floor(format_record[1]) == format_record[1];
	/*  check unvalid cases that the format don't follow standard input format.*/
	if ((format_record[1] < 0 || format_record[2] < 0) ||
		(format_record[2] != 0 && (!degree_check || !minute_check)) ||
		(format_record[1] != 0 && !degree_check)) {
		res.first = 0; 
		return res; 
	}
	res.second = (format_record[0]<0 ? -1:1)* (fabs(format_record[0]) + format_record[1]/60 
		+ format_record[2]/3600);
	
	return res;
}




