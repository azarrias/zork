#include "Room.h"
#include "globals.h"
#include <iostream>
#include "Exit.h"
#include "Item.h"
#include "Container.h"

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
	cout << " " << getName() << " " << stReset << "\n";
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
			cout << roomExit->getDescription();
			//cout << "There is an exit to the ";
			// If this room is the source room print the exit in the regular order
			if (this == roomExit->source)
				cout << roomExit->direction;
			// Otherwise, print it the other way around
			else
				cout << getOppositeDirection(roomExit->direction);
			cout << ".\n";
		}
	}
	// Diplay items
	for (Entity* const element : container) {
		if (element->type == ITEM) {
			Item* item = ((Item*)element);
			if (item->category == WEAPON) {
				cout << "A " << item->getName() << " is laying on the floor.\n";
			}
			if (item->category == CONTAINER) {
				Container* itemContainer = (Container*)item;
				if (itemContainer->isClosed == true)
					cout << "There is a closed " << itemContainer->getName() << " over there.\n";
				else {
					cout << "There is an open " << itemContainer->getName() << " over there.\n";
					if (itemContainer->container.size() > 0) {
						cout << "It contains:\n";
						for (Entity* element : itemContainer->container) {
							cout << "- " << element->getName() << "\n";
						}
					}					
				}
			}
		}
	}
}
