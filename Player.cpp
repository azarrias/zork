#include "Player.h"
#include "Room.h"
#include "Exit.h"
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

const bool Player::go(const Direction& dir)
{
	for (Entity* const element : location->container) {
		if (element->type == EXIT) {
			Exit* roomExit = ((Exit*)element);
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
