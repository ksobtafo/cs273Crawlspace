////////////////////////////////
// title: Crawlspace.h
// descr: Defines a Crawlspace as a vector of locations
//		  Goal is for an Explorer to be able to traverse
//		  a maze of locations collecting treasures.
//
// Author: Matthew Bell and Karen Sobtafo
// Last updated: 10/18/2018
////////////////////////////////

#include<vector>
#include "Location.h"

#ifndef CRAWLSPACE_H_
#define CRAWLSPACE_H_

class Crawlspace {
private:
	std::vector<Location> maze;
	unsigned short start; // The starting location for the maze
	unsigned short size;  // The total number of locations in this maze.
public:
	//When a Crawlspace is first constructed, its starting location is -2 and its size is 0.
	//i.e. there are no locations. 
	Crawlspace() : start(-1), size(0) {}

//Useful functions for designing and creating a Crawlspace:
#pragma region Design
	void addLocation(Location& l);
	void updateLoc(Exit& e, int loc);
	void updateLoc(Treasure& t, int loc);
	void setStart(unsigned short startLoc) { start = startLoc; } //Sets a new start location. The location must already be in locations, and
//we must know where it is in the vector.
#pragma endregion
};

#endif
