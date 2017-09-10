#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdexcept> 

#define MILE_UNIT 3959
using namespace std;

pair<int, double> dataConvert(string &input);
void error_print() { 
	cout << "Error: unvalid input; 4-line non-empty input requried;\n" <<
	"Standard input format for each line:\n" <<
	"\tInterger/Double or\n" <<
	"\tInteger Double (positive) or\n" << 
	"\tInteger Integer(positive) Double(postive)\n" 
	"Notice: latitude range [-90, 90], Longitude range [-180, 180]\n" 
	"\t minute and second value range [0, 60)"<< endl; 
}

int main(int argc, char** argv) {
	vector<double> location;
	string input = "";
	int read_index = 0;
	while (read_index < 4 && getline(cin, input)) {
		if (input.find_first_not_of(" \t\n") == string::npos) {
			cout << "Error: detected empty input line" << endl;
			error_print();
			return 0;
		}
		
		pair<int, double> inputRes = dataConvert(input);
		
		if (!inputRes.first ||
			(!read_index%2 && (inputRes.second > 90 || inputRes.second < -90)) ||
			(read_index%2 && (inputRes.second > 180 || inputRes.second < -180))) { 
			error_print();
			return 0; 
		}
		
		location.push_back(inputRes.second);
		read_index ++;
		input.clear();
	}
	/* check if the input contained exactly 4 lines */
	if (location.size() != 4) { 
		cout << "Error: 4-line input is required" << endl; 
		return 0; 
	}
	getline(cin, input);
	if (input.length()) 
		cout << "Warning: the program will ignore any excessive input line.\n";

	double col1     = (90-location[0])*M_PI/180;
	double col2     = (90-location[2])*M_PI/180;
	double diff_lon = (location[1]-location[3])*M_PI/180;

	double totalDistance = MILE_UNIT*acos(cos(col1)*cos(col2) 
		+ sin(col1)*sin(col2)*cos(diff_lon)); 
	cout << totalDistance << endl;
	return 1;
}

pair<int, double> dataConvert(string &input) {
	pair<int, double> res = make_pair(1, 0.0);
	vector<string> raw_record;

	istringstream iss(input);
	string s = "";
	while(iss >> s)
    	raw_record.push_back(s);

    if (raw_record.size() > 3) 
    	cout << "Warning: program will ignore excessive input in this line" << endl;

    vector<double> data_record (3, 0.0);
    int n = raw_record.size() > 3 ? 3:raw_record.size();
    for (int i = 0; i < n; ++ i) {
    	try {
    		size_t sz_index = 0;
    		data_record[i] = stod(raw_record[i], &sz_index);
    		if (sz_index < raw_record[i].length()) {
    			res.first = 0;
				return res;
    		}
    	}
    	catch (const invalid_argument& info) {
			cout << "Error: Invalid argument in stod" << endl;
			res.first = 0;
			return res;
		}
		catch (const out_of_range& info) {
			cout << "Error: Out of Range error in stod " << endl; 
			res.first = 0; 
			return res;
		}
    }

	int degree_check = floor(data_record[0]) == data_record[0],
		minute_check = floor(data_record[1]) == data_record[1];
	/*  check unvalid cases that the data don't follow standard input data.*/
	if ((data_record[1] < 0 || data_record[2] < 0) ||
		(data_record[2] != 0 && (!degree_check || !minute_check)) ||
		(data_record[1] != 0 && !degree_check) ||
		(data_record[1] >= 60 || data_record[2] >= 60)) {
		res.first = 0; 
		return res; 
	}
	res.second = (data_record[0]<0 ? -1:1)* (fabs(data_record[0]) + data_record[1]/60 
		+ data_record[2]/3600);
	return res;
}