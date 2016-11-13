#include "Entity.h"
#include <iostream>

Entity::Entity(const string& name, const string& description)
	: name(name), description(description), type(ENTITY)
{}

Entity::~Entity()
{}

const string Entity::getName() const {
	return name;
}

const string Entity::getDescription() const {
	return description;
}

void Entity::look() const {
	cout << getName() << "\n";
	cout << getDescription() << "\n";
}