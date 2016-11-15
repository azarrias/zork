#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "Entity.h"
#include <random>

class Room;
class Weapon;

class Creature : public Entity {
protected:
	const unsigned char initialHitPoints;
public:
	Creature(const string& name, const string& description, Room* initRoom, unsigned char hitPoints);
	virtual ~Creature();
	const unsigned short int rollDice(unsigned short int howManyTimes, unsigned short int nrDiceFaces) const;
	const string Creature::getStatus() const;
	Room* location;
	Weapon* equippedWeapon;
	void take(const string& item);
	//void take(const Item* item);
	bool Creature::equip(const string& item);
	void attack(Creature* enemy) const;
	char currentHitPoints;
};

#endif