#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include <iostream>

using namespace std;

Player::Player(const string& name, const string& description, Room* initRoom)
	: Creature(name, description, initRoom, rollDice(1, 6) + 4)
{
	type = PLAYER;
}

Player::~Player() 
{};

void Player::look() const
{
	location->look();
}

bool Player::look(const string& entityStr) const {
	// Elements from the room we're in
	if (this->look(entityStr, this->location->container))
		return true;

	// Elements from the inventory
	if (this->look(entityStr, this->container))
		return true;

	return false;
}

bool Player::look(const string& entityStr, const list<Entity*>& entityVector) const {
	for (Entity* element : entityVector) {
		if (entityStr.compare(element->getName()) == 0) {
			if (Creature* creature = dynamic_cast<Creature*>(element)) {
				cout << creature->getDescription();
				if (creature->getStatus().compare("DEAD") != 0)
					cout << "\nIt is " << creature->getStatus() << ".";
				return true;
			}
			else if (Item* item = dynamic_cast<Item*>(element)) {
				cout << item->getDescription();
				return true;
			}
		}
	}
	return false;
}

const bool Player::go(const Direction& dir)
{
	for (Entity* const element : location->container) {
		if (element->type == EXIT) {
			Exit* roomExit = ((Exit*)element);
			if (roomExit->isDoor == true && roomExit->isOpenDoor == false) {
				cout << "(You open the door)\n\n";
				roomExit->isOpenDoor = true;
				roomExit->updateDoorDescription();
			}				
			if (location == roomExit->source && roomExit->direction == dir) {
				location = roomExit->destination;
				return true;
			}
			else if (location == roomExit->destination && getOppositeDirection(roomExit->direction) == dir) {
				location = roomExit->source;
				return true;
			}
		}
	}
	return false;
}

const bool Player::showInventory() const {
	if (this->container.size() > 0) {
		cout << stBold << stFgBlue;
		cout << "You have got:\n";
		for (Entity* element : this->container) {
			cout << "- " << element->getName();
			if (element->type == ITEM && ((Item*)element)->category == WEAPON
				&& ((Weapon*)element) == this->equippedWeapon)
				cout << " (equipped)";
			cout << "\n";
		}
		return true;
	}
	return false;
}
