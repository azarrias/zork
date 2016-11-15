#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#ifdef toupper
#undef toupper
#endif

#include <string>
#include <vector>
#include "stylemod.h"

using namespace std;

#define GAME_TITLE "In the depths of Zork"

extern Style::Modifier stFgRed;
extern Style::Modifier stFgBlue;
extern Style::Modifier stFgYellow;
extern Style::Modifier stBold;
extern Style::Modifier stReset;
extern Style::Modifier stBgWhite;
extern Style::Modifier stBgCyan;
extern Style::Modifier stBgRed;
extern Style::Modifier stBgYellow;

void setStyles(bool useStyles);

// The order of enum values is important here, 
// to be able to calculate opposite directions
typedef enum direction { 
	U=0, D, N, S, E, W, IN, OUT } Direction;
const vector<string> validDirections = { "U", "UP", "D", "DOWN", "N", "NORTH", 
	"S", "SOUTH", "E", "EAST", "W", "WEST", "IN", "OUT" };
const Direction getOppositeDirection(const Direction& direction);
const Direction toDirection(const string& st);
const string toString(const Direction& direction);
ostream& operator<<(ostream& output, Direction const& dir);

enum GameState
{
	START, PLAY, END
};

void tokenize(const string& s, vector<string>& vect);

#endif