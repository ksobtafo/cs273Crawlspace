////////////////////////////////
// title: Location.h
// descr: Defines a location object for a crawlspace.
//		  Locations have a short name and verbose description.
//		  Locations have exits that lead to other locations in
//		  in a crawlspace.
//		  Locations have an inventory of treasures that can be
//		  updated by explorers taking said treasures.
//
// Author: Matthew Bell and Karen Sobtafo
// Last updated: 10/17/2018
////////////////////////////////

#include <string>
#include <list>
#include "Exit.h"
#include "Treasure.h"

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
private:
	std::string name;
	std::string descr;
	std::list<Exit> exits;
	std::list<Treasure> inventory;


friend class Crawlspace; // We want Crawlspace to be able to dig new exits and place treasures

	void dig(Exit e) { exits.push_back(e); }//Digs an exit from this location to another in the crawlspace
	void drop(Treasure t) { inventory.push_back(t); }//Drops a treasure in the location
public:
	Location(std::string name, std::string descr) : name(name), descr(descr) {}

	//Scans for an exit by name and returns the associated location number
	int exitLocation(std::string name);

	//Scans for a treasure and hands it over, removing it in the process from the loc
	Object* find(std::string name);

	//Display only the name
	void printName() { std::cout << name << std::endl; }

	//Displays the exits and treasures
	void listExits();
	void listTreasures();

	//Display the verbose description
	void describe();

};

#endif
