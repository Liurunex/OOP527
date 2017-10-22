#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <vector>
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
CooccurrenceMatrix<T>::CooccurrenceMatrix(vector<T> keywords): size(keywords.size()), sent_count(0) {
	for (size_t i = 0; i < keywords.size(); ++ i)
		wordMap[keywords[i]] = i;
	this->cooccurMatrix = vector<vector<double>> (size, vector<double> (size, 0));
}

template<typename T>
unordered_set<T> 
CooccurrenceMatrix<T>::readContext(istream& is) const {
	unordered_set<T> readed;
	string line;
	getline (is, line);
	if (!line.length())
		return readed;
	istringstream iss(line);
	T element;
	while (iss >> element) {
		if (wordMap.count(element))
			readed.insert(element);
	}
	return readed;
}

template<typename T>
void 
CooccurrenceMatrix<T>::update(const unordered_set<T>& context) {
	for (auto i = context.begin(); i != context.end(); ++ i) {
		auto start = i;
		start ++;
		for (auto j = start; j != context.end(); ++ j) {
			cooccurMatrix[wordMap[*i]][wordMap[*j]] += 1;
			cooccurMatrix[wordMap[*j]][wordMap[*i]] += 1;
		}
	}
}

template<typename T>
vector<double> 
CooccurrenceMatrix<T>::getVector(const T& keyword) const {
	vector<double> res (size, 0);
	if (!wordMap.count(keyword)) return res;
	res = cooccurMatrix[wordMap[keyword]];
	int temsize = sent_count;
	for_each(res.begin(), res.end(), [&temsize](int& value) {
		value /= temsize;
	});
	return res;
}

template<typename T>
void
CooccurrenceMatrix<T>::worker(istream& is) {
	unordered_set<T> context;
	while (1) {
		context = readContext(is);
		if (!context.size()) break;
		sent_count ++;
		update(context);
		context.clear();
	} 

	vector<vector<double>> res (size, vector<double> (size, 0));
	for (auto i = wordMap.begin(); i != wordMap.end(); ++ i)
		res[i->second] = getVector(i->first);
	cout << toString(res);
}

template<typename T>
string
CooccurrenceMatrix<T>::toString(vector<vector<double>>& res) const {
	string output;
	for (size_t i = 0; i < res.size(); ++ i) {
		output += "[";
		for (size_t j = 0; j < res[0].size(); ++ j) {
			output += to_string(res[i][j]);
			if (j != res[0].size()-1) output += ", ";
		}
		output += "]\n";
	}
	output.pop_back();
	return output;
}