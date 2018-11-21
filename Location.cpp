#include <stdexcept>
#include "Location.h"

int Location::exitLocation(std::string name)
{
	std::list<Exit>::iterator cur = exits.begin();
	while (cur != exits.end()) 
	{
		if (cur->getName() == name) // found it!
			return cur->getValue();
		++cur;
	}

	//Otherwise, we didn't find it
	return -1;
}

Object* Location::find(std::string name)
{
	Object* item = nullptr;
	std::list<Treasure>::iterator cur = inventory.begin();
	while (cur != inventory.end()) {
		if (cur->getName() == name) { // Found it!
			item = cur->takeme();
			inventory.erase(cur); // No longer here
			break;
		}
	}
	if (item == nullptr)
		throw std::exception("That item isn't here!");
	return item;
}

//Lists exits
void Location::listExits()
{
	std::list<Exit>::iterator it = exits.begin();
	while (it != exits.end()) {
		it->describeme();
		++it;
	}
}

//List treasures in the room inventory
void Location::listTreasures()
{
	std::list<Treasure>::iterator it = inventory.begin();
	while (it != inventory.end()) {
		it->describeme();
		++it;
	}
}

//Display the verbose description
void Location::describe()
{
	//Display the short name and overall description of the setting
	std::cout << name << std::endl;
	std::cout << descr << std::endl;

	//Display any exits
	if (!(exits.empty()))
		listExits();

	//Display any treasures
	if (!(inventory.empty()))
		listTreasures();
}
