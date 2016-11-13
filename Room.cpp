#include "Room.h"
#include "globals.h"
#include <iostream>
#include "Exit.h"
#include "Item.h"

using namespace std;

Room::Room(const string& name, const string& description)
	: Entity(name, description)
{
	type = ROOM;
}

Room::~Room()
{}

void Room::look() const
{
	cout << "   " << stBold << stBgWhite << stFgBlue;
	cout << " " << getName() << " \n" << stReset;
	cout  << stBold << stFgBlue << getDescription() << "\n";
	// Display NPCs
	for (Entity* const element : container) {
		if (element->type == NPCHAR) {
			cout << "There is a " << element->getName() << " in here.\n" << element->getDescription() << "\n";
		}
	}
	// Display exits
	for (Entity* const element : container) {
		if (element->type == EXIT) {
			Exit* roomExit = ((Exit*)element);
			cout << "There is an exit to the ";
			// If this room is the source room print the exit in the regular order
			if (this == roomExit->source)
				cout << roomExit->direction << "\n";
			// Otherwise, print it the other way around
			else
				cout << getOppositeDirection(roomExit->direction) << "\n";
		}
	}
	// Diplay items
	for (Entity* const element : container) {
		if (element->type == ITEM) {
			Item* item = ((Item*)element);
			if (item->category == WEAPON) {
				cout << "A " << item->getName() << " is laying on the floor.\n";
			}
			
		}
	}
}
