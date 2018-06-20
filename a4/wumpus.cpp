#include "wumpus.h"

wumpus::wumpus() : event()
{
	dead = 0;
	set_name();
}

wumpus::~wumpus(){}

void wumpus::set_name()
{
	name = 'W';
}

void wumpus::percepts()
{
	cout << "You smell a terrible stench." << endl;
}

void wumpus::display_percepts()
{
	percepts();
}