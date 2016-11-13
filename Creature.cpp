#include "Creature.h"
#include <iostream>

Creature::Creature(const string& name, const string& description, Room* initRoom, unsigned char hitPoints)
	: Entity(name, description), location(initRoom), initialHitPoints(hitPoints), currentHitPoints(hitPoints)
{
	type = CREATURE;
}

Creature::~Creature()
{}

const unsigned char Creature::rollDice(unsigned char howManyTimes, unsigned char nrDiceFaces) const {
	unsigned char result = 0;
	if (nrDiceFaces >= 4 && nrDiceFaces <= 12 && nrDiceFaces % 2 == 0) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, nrDiceFaces);

		for (int n = 0; n < howManyTimes; n++)
			result += dis(gen);
	}
	
	return result;
}

const string Creature::showStatus() const {
	unsigned char healthRatio = currentHitPoints * 100 / initialHitPoints;
	if (healthRatio > 95) return "IN PERFECT HEALTH";
	else if (healthRatio > 70) return "SLIGHTLY WOUNDED";
	else if (healthRatio > 50) return "WOUNDED";
	else if (healthRatio > 25) return "SEVERILY WOUNDED";
	else return "LETHALLY WOUNDED";
}
