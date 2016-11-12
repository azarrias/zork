#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#ifdef toupper
#undef toupper
#endif

#include <string>
#include <vector>

using namespace std;

#define GAME_TITLE "In the depths of Zork"
extern bool USE_STYLES;

typedef enum direction { U, D, N, E, S, W, IN, OUT } Direction;

void tokenize(const string& s, vector<string>& vect);
bool parse(vector<string>& vect);

#endif