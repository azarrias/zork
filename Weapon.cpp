#include "Weapon.h"

Weapon::Weapon(const string& name, const string& description, Room* initRoom,
	const unsigned char damageDiceSides, const unsigned char fixedDamage)
	: Item(name, description, initRoom), damageDiceSides(damageDiceSides), 
	fixedDamage(fixedDamage)
{
	type = ITEM;
	category = WEAPON;
}

Weapon::~Weapon()
{}
