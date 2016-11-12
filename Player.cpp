#include "Player.h"

Player::Player(const string& name, const string& description, Room* initRoom)
	: Creature(name, description, initRoom) 
{}

Player::~Player() 
{};