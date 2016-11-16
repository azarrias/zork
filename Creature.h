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
	const bool take(const string& item);
	const bool drop(const string& item);
	//void take(const Item* item);
	const bool equip(const string& item);
	void attack(Creature* enemy) const;
	const bool put(const string& inventoryItem, const string& itemContainer);
	const bool drink(const string& drinkItem);
	const bool eat(const string& foodItem);
	const bool open(const Direction& dir);
	const bool close(const Direction& dir);
	char currentHitPoints;
};

#endif