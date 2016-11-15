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
	else if (argc == 2) setStyles(false);

	GameState gameState = GameState::START;

	World* world = nullptr;
	string userInput;
	// Maybe this should be changed to a list
	vector<string> tokenizedInput;
	tokenizedInput.reserve(10);

	while (gameState != GameState::END) {

		switch (gameState)
		{
		case START:
			world = new World();

			cout << stBold << stFgRed << "##############################################\n";
			cout << "##  Welcome to " << stBgRed << stFgYellow << " " GAME_TITLE << " !!! ";
			cout << stReset << stBold << stFgRed << "  ##\n";
			cout << "##############################################" << stReset << "\n\n" << stBold << stFgBlue;
			cout << "You wake up drooling on the floor of an unfamiliar place.\n";
			cout << "The touch of the stone-cold floor tiles and the bad taste in your mouth\n";
			cout << "make you feel sick. As you slowly regain consciousness, you try to figure\n"; 
			cout << "everything out...but nothing comes up and eventually you realize that you\n";
		    cout << "have lost your memories.\nYou aren't even fully aware of who you are anymore.\n";
			cout << "What to do ? Where to go ?\n";
			cout << "You are determined to find answers to all these questions...\n\n";

			gameState = PLAY;
			userInput = "LOOK";
			break;

		case PLAY:
			do {
				tokenize(userInput, tokenizedInput);
				if ((gameState = world->parse(tokenizedInput)) != PLAY) break;
				cout << stReset << "\n> ";
			} while (getline(cin, userInput));
			if (gameState == START) {
				delete world;
			}
			cout << stReset;
			break;
		}
	}

	return 0;
}