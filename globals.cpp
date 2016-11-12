#include "globals.h"
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <iostream>
using namespace std;

bool USE_STYLES = true;

void tokenize(const string& s, vector<string>& vect) {
	if (vect.size() > 0) vect.clear();
	stringstream stringStream(s);
	string item;
	while (getline(stringStream, item, ' ')) {
		if (!item.empty()) {
			transform(item.begin(), item.end(), item.begin(), toupper);
			vect.push_back(item);
		}
	}
}

bool parse(vector<string>& vect) {
	if (vect.size() == 0) return false;
	if (vect.front().compare("GO") == 0) 
		vect.erase(vect.begin());

	return false;
}