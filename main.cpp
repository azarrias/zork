#include "stylemod.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool USE_STYLES = true;

int main(int argc, char* argv[])
{
	// Check command line arguments
	if (argc > 1 && strcmp(argv[1], "-nocolor")) {
		cout << "Invalid arguments.\n" << "Usage: " << argv[0] << "\n";
		cout << "   or: " << argv[0] << " -nocolor\n";
		exit(0);
	}
	else if (argc == 2) USE_STYLES = false;

	string userInput;
	vector<string> command;
	command.reserve(10);

	Style::Modifier red(Style::FG_RED, USE_STYLES);
	Style::Modifier bold(Style::BOLD, USE_STYLES);
	Style::Modifier reset(Style::RESET, USE_STYLES);

	cout << "Welcome to " << red << bold << "ZORK APOCALYPSE PARTY\n" << reset;
	cout << "> ";

	while (getline(cin, userInput)) {
		if (command.size() > 0) command.clear();
		stringstream ss(userInput);
		string item;
		while (getline(ss, item, ' ')) {
			if (!item.empty()) command.push_back(item);
		}
		cout << "> ";
	}

	return 0;
}