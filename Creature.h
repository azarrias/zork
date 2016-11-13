#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "Entity.h"
#include <random>

class Room;

class Creature : public Entity {
protected:
	const unsigned char initialHitPoints;
	unsigned char currentHitPoints;
public:
	Creature(const string& name, const string& description, Room* initRoom, unsigned char hitPoints);
	virtual ~Creature();
	const unsigned char rollDice(unsigned char howManyTimes, unsigned char nrDiceFaces) const;
	const string Creature::showStatus() const;
	Room* location;
};

#endif