#include "globals.h"
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include <iostream>
using namespace std;

Style::Modifier stFgRed(Style::FG_RED);
Style::Modifier stFgBlue(Style::FG_BLUE);
Style::Modifier stFgYellow(Style::FG_YELLOW);
Style::Modifier stBold(Style::BOLD);
Style::Modifier stReset(Style::RESET);
Style::Modifier stBgWhite(Style::BG_LIGHT_GRAY);
Style::Modifier stBgCyan(Style::BG_CYAN);
Style::Modifier stBgRed(Style::BG_RED);
Style::Modifier stBgYellow(Style::BG_YELLOW);

void setStyles(bool useStyles) {
	stFgRed.setUseStyles(useStyles);
	stFgBlue.setUseStyles(useStyles);
	stFgYellow.setUseStyles(useStyles);
	stBold.setUseStyles(useStyles);
	stReset.setUseStyles(useStyles);
	stBgWhite.setUseStyles(useStyles);
	stBgCyan.setUseStyles(useStyles);
	stBgRed.setUseStyles(useStyles);
	stBgYellow.setUseStyles(useStyles);
}

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

const Direction getOppositeDirection(const Direction& direction) {
	if (direction % 2 == 0) return (Direction)(direction + 1);
	else return (Direction)(direction - 1);
}

const string toString(const Direction& direction) {
	switch (direction) {
	case Direction::U:	return "UP"; break;
	case Direction::D:	return "DOWN"; break;
	case Direction::N: return "NORTH"; break;
	case Direction::S: return "SOUTH"; break;
	case Direction::E: return "EAST"; break;
	case Direction::W: return "WEST"; break;
	case Direction::IN: return "INSIDE"; break;
	case Direction::OUT: return "OUTSIDE"; break;
	default: return "I don't know where!!!";
	}
}

const Direction toDirection(const string& st) {
	if (st == "U" || st == "UP") return Direction::U;
	else if (st == "D" || st == "DOWN") return Direction::D;
	else if (st == "N" || st == "NORTH") return Direction::N;
	else if (st == "S" || st == "SOUTH") return Direction::S;
	else if (st == "E" || st == "EAST") return Direction::E;
	else if (st == "W" || st == "WEST") return Direction::W;
	else if (st == "IN") return Direction::IN;
	else if (st == "OUT") return Direction::OUT;
	return Direction::OUT;
}

ostream& operator<<(ostream& output, Direction const& dir) {
	return output << toString(dir);
}
