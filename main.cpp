#include "stylemod.h"
#include "globals.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	// Check command line arguments in order to use color or not
	if (argc > 1 && strcmp(argv[1], "-nocolor")) {
		cout << "Invalid arguments.\n" << "Usage: " << argv[0] << "\n";
		cout << "   or: " << argv[0] << " -nocolor\n";
		exit(0);
	}
	else if (argc == 2) USE_STYLES = false;

	World world;
	string userInput;
	// Maybe this should be changed to a list
	vector<string> tokenizedInput;
	tokenizedInput.reserve(10);
	bool userCommand = false;

	Style::Modifier red(Style::FG_RED, USE_STYLES);
	Style::Modifier bold(Style::BOLD, USE_STYLES);
	Style::Modifier reset(Style::RESET, USE_STYLES);

	cout << "Welcome to " << red << bold << GAME_TITLE << "\n" << reset;
	cout << "> ";

	while (getline(cin, userInput)) {
		tokenize(userInput, tokenizedInput);
		userCommand = parse(tokenizedInput);
		cout << "> ";
	}

	return 0;
}