#include "pit.h"

pit::pit() : event()
{
	set_name();
}

pit::~pit(){}

void pit::set_name()
{
	name = 'P';
}

void pit::percepts()
{
	cout << "You feel a breeze." << endl;
}

void pit::display_percepts()
{
	percepts();
}