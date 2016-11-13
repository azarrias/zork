#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "globals.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

World::World() {
	Room* cellNo4 = new Room("Cell no. 4", "Starting room");
	Room* corridor2 = new Room("Corridor 2", "TBD");
	Exit* cellNo4_Corridor = new Exit(Direction::N, cellNo4, corridor2);
	player = new Player("Hero", "Badass", cellNo4);
};

World::~World() 
{};

GameState World::parse(vector<string>& vect) {
	if (vect.size() == 0) return PLAY;
	if (vect.front().compare("GO") == 0)
		vect.erase(vect.begin());
	switch (vect.size()) {
		case 1:
		{
			if (vect.front().compare("Q") == 0 ||
				vect.front().compare("QUIT") == 0) {
				cout << stFgYellow << "Game closed\n\n" << stBold << stFgBlue;
				return END;
			}
			else if (vect.front().compare("HELP") == 0) {
				// void displayHelp();
			}
			else if (vect.front().compare("INFO") == 0 ||
				vect.front().compare("ABOUT") == 0) {
				// void displayInfo();
			}
			else if (vect.front().compare("SAVE") == 0) {
				// void saveGame();
			}
			else if (vect.front().compare("RESTORE") == 0 ||
				vect.front().compare("LOAD") == 0) {
				// void loadGame();
			}
			else if (vect.front().compare("RESTART") == 0) {
				cout << stFgYellow << "Game restarted\n\n" << stBold << stFgBlue;
				return START;
			}
			else if (vect.front().compare("L") == 0 ||
				vect.front().compare("LOOK") == 0) {
				player->look();
			}
			else {
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect.front());
				if (it != validDirections.cend()) {
					if(player->go(toDirection(vect.front())))
						player->look();
					else
						cout << stBold << stFgBlue << "There is no exit that way...\n";
				}
			}
			break;
		}
		default:
		{
			cout << "I beg your pardon?\n";
		}
	}
	return PLAY;
}