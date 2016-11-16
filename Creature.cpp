#include "Creature.h"
#include "Weapon.h"
#include "Room.h"
#include "Container.h"
#include "Exit.h"
#include <iostream>

Creature::Creature(const string& name, const string& description, Room* initRoom, unsigned char hitPoints)
	: Entity(name, description), location(initRoom), initialHitPoints(hitPoints), currentHitPoints(hitPoints),
	  equippedWeapon(nullptr)
{
	type = CREATURE;
}

Creature::~Creature()
{}

const unsigned short int Creature::rollDice(unsigned short int howManyTimes, unsigned short int nrDiceFaces) const {
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

const string Creature::getStatus() const {
	unsigned char healthRatio = currentHitPoints * 100 / initialHitPoints;
	if (healthRatio > 95) return "IN PERFECT HEALTH";
	else if (healthRatio > 70) return "SLIGHTLY WOUNDED";
	else if (healthRatio > 50) return "WOUNDED";
	else if (healthRatio > 25) return "SEVERILY WOUNDED";
	else if (healthRatio > 0) return "LETHALLY WOUNDED";
	else return "DEAD";
}

const bool Creature::take(const string& item) {
	for (Entity* element : this->location->container) {
		if (element->type == ITEM && item.compare(element->getName()) == 0
			&& ((Item*)element)->category != CONTAINER) {
			this->container.push_back(element);
			this->location->container.remove(element);
			return true;
		}
	}
	return false;
}

const bool Creature::drop(const string& item) {
	for (Entity* element : this->container) {
		if (item.compare(element->getName()) == 0) {
			this->location->container.push_back(element);
			this->container.remove(element);
			cout << "You drop the " << element->getName();
			cout << " on the floor.\n";
			return true;
		}
	}
	return false;
}

const bool Creature::equip(const string& item) {
	for (Entity* element : this->container) {
		if (element->type == ITEM && ((Item*)element)->category == WEAPON &&
			element->getName() == item) {
			this->equippedWeapon = (Weapon*)element;
			return true;
		}
	}
	return false;
}

void Creature::attack(Creature* enemy) const {
	unsigned short int damage, attackRoll, defendRoll;
	attackRoll = this->rollDice(1, 10);
	defendRoll = this->rollDice(1, 6);

	cout << stBold << stFgBlue;
	if (enemy->currentHitPoints > 0) {
		if (attackRoll > defendRoll) {
			cout << this->getName() << " attacks " << enemy->getName();
			if (this->equippedWeapon != nullptr) {
				cout << " with " << this->equippedWeapon->getName() << ".\n";
				damage = this->rollDice(1, this->equippedWeapon->damageDiceSides);
				damage += this->equippedWeapon->fixedDamage;
			}
			else {
				cout << " with bare hands.\n";
				damage = this->rollDice(1, 4);
			}
			cout << "The " << enemy->getName() << " takes " << damage << " damage.\n";
			enemy->currentHitPoints -= damage;
		}
		else {
			cout << this->getName() << " misses " << enemy->getName() << ".\n";
		}
		if (enemy->currentHitPoints <= 0) {
			cout << "The " << enemy->getName() << " drops dead.\n";
			for (Entity* element : enemy->container) {
				location->container.push_back(element);
				cout << element->getName() << " falls to the ground.\n";
			}
			enemy->container.clear();
			enemy->description = "It is dead.";
		}
	}
	else {
		cout << "You can't kill what's already dead...unless they're zombies :P.\n";
	}
}

const bool Creature::put(const string& inventoryItemStr, const string& itemContainerStr) {
	for (Entity* inventoryElement : this->container) {
		if (inventoryElement->type == ITEM && inventoryItemStr.compare(inventoryElement->getName()) == 0) {
			for (Entity* roomElement : this->location->container) {
				if (roomElement->type == ITEM && ((Item*)roomElement)->category == CONTAINER &&
					itemContainerStr.compare(roomElement->getName()) == 0) {
					Container* newRecipient = (Container*)roomElement;
					if (newRecipient->isClosed == false) {
						this->container.remove(inventoryElement);
						newRecipient->container.push_back(inventoryElement);
						return true;
					}
				}
			}
		}
	}
	return false;
}

const bool Creature::open(const Direction& dir) {
	for (Entity* const element : this->location->container) {
		if (element->type == EXIT) {
			Exit* roomExit = ((Exit*)element);
			if (this->location == roomExit->source && dir == roomExit->direction ||
				this->location == roomExit->destination && dir == getOppositeDirection(roomExit->direction)) {
				//there is an exit this way
				if (roomExit->isDoor == true) {
					if (roomExit->isOpenDoor == false) {
						roomExit->isOpenDoor = true;
						roomExit->updateDoorDescription();
						return true;
					}
					else return false;
				}
				else return false;
			}
		}
	}
	return false;
}

const bool Creature::close(const Direction& dir) {
	for (Entity* const element : this->location->container) {
		if (element->type == EXIT) {
			Exit* roomExit = ((Exit*)element);
			if (this->location == roomExit->source && dir == roomExit->direction ||
				this->location == roomExit->destination && dir == getOppositeDirection(roomExit->direction)) {
				//there is an exit this way
				if (roomExit->isDoor == true) {
					if (roomExit->isOpenDoor == true) {
						roomExit->isOpenDoor = false;
						roomExit->updateDoorDescription();
						return true;
					}
					else return false;
				}
				else return false;
			}
		}
	}
	return false;
}