#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Creature.h"

class Player : public Creature {
public:
	Player(const string& name, const string& description, Room* initRoom);
	virtual ~Player();
	void look() const;
	const bool go(const Direction& dir);
};

#endif