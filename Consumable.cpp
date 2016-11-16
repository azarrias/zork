#include "Consumable.h"

Consumable::Consumable(const string& name, const string& description, Room* initRoom,
	const unsigned char damageDiceSides, const unsigned char fixedDamage)
	: Item(name, description, initRoom), healDiceSides(healDiceSides),
	healFixed(healFixed)
{
	type = ITEM;
	category = CONSUMABLE;
}

Consumable::~Consumable()
{}
