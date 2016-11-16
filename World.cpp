#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "NPC.h"
#include "globals.h"
#include "Weapon.h"
#include "Creature.h"
#include "Container.h"
#include "Item.h"
#include "Consumable.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

World::World() 
	: startTime(time(NULL)) {

	Room* cellNo1 = new Room("Cell no. 1", "The smell in this room is so strong that it kinda feels like a vapor sauna.\nQuickly you notice where it comes from.");
	Room* cellNo2 = new Room("Cell no. 2", "There is another security bed in the center of this room.\nThe following phrase is written repeatedly all over the walls:\nThere is a small mailbox here. But as a matter of fact you can't see any mailbox in here.");
	Room* cellNo3 = new Room("Cell no. 3", "There is an old mattress on the floor.\nIt looks particularly uncomfortable.");
	Room* cellNo4 = new Room("Cell no. 4", "The appearance of the room where you woke up gives you the goosebumps.\nIt looks like you might be confined in a jailhouse or mental institution.\nWhy or how that happened is a mystery to you.\nThere is a security bed in the center of the room.\nIt seems as if its safety straps have been forced.\nDid you force them?");
	Room* cellNo5 = new Room("Cell no. 5", "There is some surgery equipment all made a mess...your guess is that\nsome doctor was performing an operation and had to run away, leaving\nall of this behind.");
	Room* cellNo6 = new Room("Cell no. 6", "There are some mortal remains stacked up in a corner.\nSome of the bones don't look human...good vibes all around.");
	Room* cellNo7 = new Room("Cell no. 7", "In the bed of this room, there is a notebook full of handwritten notes.\nYou read the last one:\n\"All the shouting that comes from the cell to the other side is driving\nme even crazier than what got me here. The staff here couldn't care\nless about us...\"\n...the rest of this paper sheet has been ripped off, so this is it.");
	Room* cellNo8 = new Room("Cell no. 8", "The bed in this room is dirty and full of blood.\nYou don't want to imagine what happened here...but you want out!");

	entities.push_back(cellNo1);
	entities.push_back(cellNo2);
	entities.push_back(cellNo3);
	entities.push_back(cellNo4);
	entities.push_back(cellNo5);
	entities.push_back(cellNo6);
	entities.push_back(cellNo7);
	entities.push_back(cellNo8);

	Room* corridor1 = new Room("Corridor", "The West end of the corridor has a small window to the outside.\nIt's made of tempered safety glass so you shouldn't dream about that\nescape route.");
	Room* corridor2 = new Room("Corridor", "You find yourself in a long and narrow corridor that communicates\nmany rooms.");
	Room* corridor3 = new Room("Corridor", "In this part of the corridor you can see a big room in the distance.");
	Room* corridor4 = new Room("Corridor", "This is the Eastern endpoint of the corridor.\nIt communicates the cluster of rooms with the rest of the facility.");

	entities.push_back(corridor1);
	entities.push_back(corridor2);
	entities.push_back(corridor3);
	entities.push_back(corridor4);

	Room* maintenanceRoom = new Room("Maintenance Room", "The Maintenance Room is full of all kinds of objects, such as pallets,\nbrooms, mops, pickers...");
	Room* staffRoom = new Room("Staff Room", "This room doesn't seem very interesting, it's full of office stuff.");
	Room* securityCabin = new Room("Security Cabin", "You can see two rows of monitors on the security booth.\nIt would be great to see what's going on in the other rooms, but all\nyou can see on screen is a random pattern of static...it seems that the\ncamera system has been sabotaged.");

	entities.push_back(maintenanceRoom);
	entities.push_back(staffRoom);
	entities.push_back(securityCabin);

	Room* lobby = new Room("Lobby", "The open space before you is overwhelming, specially in contrast with\nthe rest of the facilities. A song that you're not able to recognize is\nplaying on an old turntable.\nThe room has a certain flair, but it is clear that it has been severely\nneglected. It seems that this room has been used for leisure activities.");
	Room* hallway = new Room("Hallway", "This small passage joins the office area on the upper floor with all the\nmain facilities on the ground floor.");
	Room* office = new Room("Office", "There is a large mahogany desk in front of you with very metodically\norganized paperwork on top.\nOn the table, a computer with a game on screen that you quickly\nrecognize: Zork.\nYou have a flashback that blows your head off, indeed you were playing\nZork just before you passed out!\nOK now...this is quite something to digest...when you look inpect it\nclosely you see that the text on screen describes your surroundings,\nyou find out the way to put an end to all this madness. You smile while\nyou sit down to type your next command:");

	entities.push_back(lobby);
	entities.push_back(hallway);
	entities.push_back(office);

	Exit* cellNo1_Corridor = new Exit(Direction::S, cellNo1, corridor1, true);
	Exit* cellNo2_Corridor = new Exit(Direction::N, cellNo2, corridor1, true);
	Exit* cellNo3_Corridor = new Exit(Direction::S, cellNo3, corridor2, true);
	Exit* cellNo4_Corridor = new Exit(Direction::N, cellNo4, corridor2, true);
	Exit* cellNo5_Corridor = new Exit(Direction::S, cellNo5, corridor3, true);
	Exit* cellNo6_Corridor = new Exit(Direction::N, cellNo6, corridor3, true);
	Exit* cellNo7_Corridor = new Exit(Direction::S, cellNo7, corridor4, true);
	Exit* cellNo8_Corridor = new Exit(Direction::N, cellNo8, corridor4, true);

	entities.push_back(cellNo1_Corridor);
	entities.push_back(cellNo2_Corridor);
	entities.push_back(cellNo3_Corridor);
	entities.push_back(cellNo4_Corridor);
	entities.push_back(cellNo5_Corridor);
	entities.push_back(cellNo6_Corridor);
	entities.push_back(cellNo7_Corridor);
	entities.push_back(cellNo8_Corridor);

	Exit* corridor1_Corridor2 = new Exit(Direction::E, corridor1, corridor2, false);
	Exit* corridor2_Corridor3 = new Exit(Direction::E, corridor2, corridor3, false);
	Exit* corridor3_Corridor4 = new Exit(Direction::E, corridor3, corridor4, false);

	entities.push_back(corridor1_Corridor2);
	entities.push_back(corridor2_Corridor3);
	entities.push_back(corridor3_Corridor4);

	Exit* corridor4_security = new Exit(Direction::E, corridor4, securityCabin, true);
	Exit* security_maintenance = new Exit(Direction::N, securityCabin, maintenanceRoom, true);
	Exit* security_staff = new Exit(Direction::S, securityCabin, staffRoom, true);

	entities.push_back(corridor4_security);
	entities.push_back(security_maintenance);
	entities.push_back(security_staff);

	Exit* security_lobby = new Exit(Direction::E, securityCabin, lobby, true);
	Exit* lobby_hallway = new Exit(Direction::U, lobby, hallway, false, false, "There is a Spiral staircase that goes ");
	Exit* hallway_office = new Exit(Direction::N, hallway, office, true);

	entities.push_back(security_lobby);
	entities.push_back(lobby_hallway);
	entities.push_back(hallway_office);

	player = new Player("PLAYER", "You have a face that only a mother could love.", cellNo4);
	NPC* ork = new NPC("ORK", "The ORK is staring at you with a hungry face.", cellNo1, 5);
	NPC* troll = new NPC("TROLL", "The TROLL is looking at you with a scowl.", cellNo3, 6);
	Item* keycard = new Item("KEYCARD", "This is a security CARD to gain access to some room", cellNo3);
	corridor4_security->setKey(keycard);

	troll->take("KEYCARD");

	entities.push_back(player);
	entities.push_back(ork);

	Weapon* axe = new Weapon("AXE", "The AXE edge looks sharp.", cellNo1, 6, 1);
	Weapon* copperDagger = new Weapon("DAGGER", "The DAGGER is made of copper.", cellNo4, 4, 1);
	Weapon* scalpel = new Weapon("SCALPEL", "The SCALPEL is shiny and sharp.", cellNo5, 4, 2);

	entities.push_back(axe);
	entities.push_back(copperDagger);

	ork->take("AXE");
	ork->equip("AXE");

	Container* chest = new Container("CHEST", "The CHEST is quite big...you wonder if it will be full of treasures.", maintenanceRoom);
	Consumable* potion = new Consumable("POTION", "The POTION looks healthy", maintenanceRoom, 4, 1);
	Consumable* sandwich = new Consumable("SANDWICH", "Not your favorite SANDWICH, but...", staffRoom, 4, 1);

	chest->container.push_back(potion);
	maintenanceRoom->container.remove(potion);
	
	score = 0;
};

World::~World() 
{
	for (Entity* element : entities)
		delete element;

	entities.clear();
};

GameState World::parse(vector<string>& vect) {
	if (vect.size() == 0) return PLAY;
	// if present, discard the "optional" GO keyword
	if (vect.front().compare("GO") == 0)
		vect.erase(vect.begin());
	switch (vect.size()) {
		case 1:
		{
			if (vect.front().compare("Q") == 0 ||
				vect.front().compare("QUIT") == 0) {
				if (player->location->getName().compare("Office") == 0) {
					cout << stFgYellow << "Congratulations! You did it! You finished the game! :)";
					cout << "\nYou were playing this game for ";
					displayTime();
					cout << "Your score was " << score << ".\n";
				}
				cout << stFgYellow << "Game closed.\n\n" << stBold << stFgBlue;
				return END;
			}
			else if (vect.front().compare("INFO") == 0 ||
				vect.front().compare("ABOUT") == 0) {
				// void displayInfo();
			}
			else if (vect.front().compare("RESTART") == 0) {
				cout << stFgYellow << "Game restarted.\n\n" << stBold << stFgBlue;
				return START;
			}
			else if (vect.front().compare("L") == 0 ||
				vect.front().compare("LOOK") == 0) {
				player->look();
			}
			else if (vect.front().compare("SCORE") == 0) {
				cout << stFgYellow << "Your current score is " << score << ".\n";
				cout << stBold << stFgBlue;
			}
			else if (vect.front().compare("TIME") == 0) {
				cout << stFgYellow << "You have been playing this game for ";
				displayTime();
			}
			else if (vect.front().compare("STATUS") == 0 ||
				vect.front().compare("DIAGNOSE") == 0) {
				cout << stBold << stFgBlue << "You are " << player->getStatus() << ".\n";
			}
			else if (vect.front().compare("I") == 0 ||
				vect.front().compare("INVENTORY") == 0) {
				if (player->showInventory() == false) {
					cout << "You haven't got any items in your inventory.\n";
				}
			}
			else { // GO commands
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect.front());
				if (it != validDirections.cend()) {
					if(player->go(toDirection(vect.front())))
						player->look();
					else cout << stBold << stFgBlue << "There is no exit that way...\n";
				}
				else cout << stBold << stFgBlue << "That direction is invalid...\n";
			}
			break;
		}
		case 2:
		{
			if (vect.front().compare("TAKE") == 0 ||
				vect.front().compare("GET") == 0) {
				cout << stBold << stFgBlue;
				if (player->take(vect[1]))
					cout << "You take the " << vect[1] << ".\n";
				else cout << "You can't take that.\n";
			}
			if (vect.front().compare("DROP") == 0) {
				cout << stBold << stFgBlue;
				if (player->drop(vect[1]))
					cout << "You drop the " << vect[1] << " on the floor.\n";
				else cout << "You can't drop what you haven't got.\n";
			}
			if (vect.front().compare("EQUIP") == 0) {
				cout << stBold << stFgBlue;
				if (player->equip(vect[1])) 
					cout << "You equip the " << vect[1] << ".\n";
				else cout << "You can't equip that.\n";
			}
			if (vect.front().compare("ATTACK") == 0) {
				for (Entity* element : player->location->container) {
					if (element->type == NPCHAR && vect[1].compare(element->getName()) == 0) {
						if(player->attack((Creature*)element))
							score += 10;
						if(((Creature*)element)->currentHitPoints > 0)
							((Creature*)element)->attack(player);
						break;
					}
				}
			}
			if (vect.front().compare("LOOK") == 0) {
				cout << stBold << stFgBlue;
				if (player->look(vect[1]) == false)
					cout << "What is it that you want to look?";
				cout << "\n";
			}
			break;
		}
		case 3:
		{
			if (vect.front().compare("PICK") == 0 &&
				vect[1].compare("UP") == 0) {
				cout << stBold << stFgBlue;
				if (player->take(vect[2]))
					cout << "You take the " << vect[2] << ".\n";
				else cout << "You can't take that.\n";
			}
			if (vect.front().compare("OPEN") == 0 && vect[2].compare("DOOR") == 0) {
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect[1]);
				if (it != validDirections.cend()) {
					if (player->open(toDirection(vect[1])))
						cout << "You open the " << vect[1] << " DOOR.\n";
					else cout << stBold << stFgBlue << "There is no door to be opened in that direction.\n";
				}
				else cout << stBold << stFgBlue << "That direction is invalid...\n";
			}
			if (vect.front().compare("CLOSE") == 0 && vect[2].compare("DOOR") == 0) {
				vector<string>::const_iterator it;
				it = find(validDirections.begin(), validDirections.cend(), vect[1]);
				if (it != validDirections.cend()) {
					if (player->close(toDirection(vect[1])))
						cout << "You close the " << vect[1] << " DOOR.\n";
					else cout << stBold << stFgBlue << "There is no door to be closed in that direction.\n";
				}
				else cout << stBold << stFgBlue << "That direction is invalid...\n";
			}
			break;
		}
		case 4:
		{
			if ((vect.front().compare("PUT") == 0 || vect.front().compare("DROP")) && 
				(vect[2].compare("IN") == 0 || vect[2].compare("INTO") == 0)) {
				cout << stBold << stFgBlue;
				if (player->put(vect[1], vect[3])) {
					cout << "You put the " << vect[1] << " in the " << vect[3] << ".\n";
				}
				else
					cout << "I'm afraid that's not possible.\n";
			}
			break;
		}
		default:
		{
			cout << stBold << stFgBlue << "I beg your pardon?\n";
		}
	}
	if (player->currentHitPoints <= 0) {
		cout << stFgYellow << "\nYou were playing this game for ";
		displayTime();
		cout << stFgYellow << "Your score was " << score << ".\n";
		cout << "Press ENTER key to restart...\n";
		cin.get();
		return START;
	}
	else return PLAY;
}

void World::displayTime() const {
	unsigned int seconds = (unsigned int)difftime(time(NULL), startTime);
	if (seconds >= 3600) {
		cout << seconds / 3600 << " hour(s) ";
	}
	if (seconds >= 60) {
		cout << seconds / 60 % 3600 << " minute(s) ";
	}
	cout << seconds % 60 << " seconds.\n";
}