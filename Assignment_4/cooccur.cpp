#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::unordered_set;
using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::getline;
using std::istream;
using std::istringstream;
using std::to_string;

template<typename T>
CooccurrenceMatrix<T>::CooccurrenceMatrix(vector<T> keywords): size(keywords.size()) {
	for (size_t i = 0; i < keywords.size(); ++ i)
		wordMap[keywords[i]] = i;
	this->cooccurMatrix = vector<vector<double>> (size, vector<double> (size, 0));
}

template<typename T>
unordered_set<T> CooccurrenceMatrix<T>::readContext(istream& is) const {
	unordered_set<T> readed;
	string line;
	if (!getline (is, line))
		throw "completed reading action";
	istringstream iss(line);
	T element;
	while (iss >> element) {
		if (wordMap.count(element))
			readed.insert(element);
	}
	return readed;
}

template<typename T>
void CooccurrenceMatrix<T>::update(const unordered_set<T>& context) {
	for (auto i = context.begin(); i != context.end(); ++ i) {
		for (auto j = i; j != context.end(); ++ j) {
			cooccurMatrix[wordMap[*i]][wordMap[*j]] += 1;
			if (j != i)
				cooccurMatrix[wordMap[*j]][wordMap[*i]] += 1;
		}
	}
}

template<typename T>
vector<double> CooccurrenceMatrix<T>::getVector(const T& keyword) const {
	vector<double> res (size, 0);
	if (!wordMap.count(keyword)) return res;
	//int index = wordMap[keyword];
	int index = wordMap.find(keyword)->second;
	res = cooccurMatrix[index];
	int temsize = cooccurMatrix[index][index] == 0 ? 1:cooccurMatrix[index][index];
	for_each(res.begin(), res.end(), [&temsize](double& value) {
		value /= temsize;
	});
	return res;
}

template<typename T>
void CooccurrenceMatrix<T>::worker(istream& is, vector<T> keywords) {
	unordered_set<T> context;
	string line;
	try {
		for (;;) {
			context = readContext(is);
			update(context);
			context.clear();
		}	
	}
	catch (const char* msg) {
		//cout << msg << endl;
	}

	for (size_t i = 0; i < keywords.size(); ++ i) {
		vector<double> itvec = getVector(keywords[i]);
		printhelper(itvec, keywords[i]);
	}
}

template<typename T>
void CooccurrenceMatrix<T>::printhelper(vector<double>& res, const T& keyword) const {
	cout << keyword << ": ["; 
	string output;
	for (size_t i = 0; i < res.size(); ++ i) {
		output += to_string(res[i]);
		if (i != res.size()-1) output += ", ";
	}
	output += "]\n";
	cout << output;
}

