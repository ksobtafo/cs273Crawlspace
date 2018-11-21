#include "Crawlspace.h"

void Crawlspace::addLocation(Location & l)
{

	Location *NewLocation = new Location (l);
	// dereference later 
// Adds a location to the crawlspace
//@param l is a reference to a location.
//Postcondition: a new location is added to the crawlspace


};
	 


void Crawlspace::updateLoc(Exit & e, int loc)
{
	Exit *NewExit = new Exit (e);
	/*****************************
	* Adds an exit to an existing location
	* @param e is an exit
	* @param loc is the location to which an exit is being added
	* Postcondition: a new exit is added to the crawlspace
	******************************/
}

void Crawlspace::updateLoc(Treasure & t, int loc)
{

	/*****************************
	* Drops a treasure into an existing location
	* @param t is an treasure
	* @param loc is the location into which t is being dropped
	* Postcondition: a new treasure is added to the crawlspace
	******************************/
}
