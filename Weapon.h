#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"

class Weapon : public Item {
public:
	Weapon(const string& name, const string& description, Room* initRoom,
		const unsigned char damageDiceSides, const unsigned char fixedDamage);
	virtual ~Weapon();
	unsigned char damageDiceSides;
	unsigned char fixedDamage;
};

#endif