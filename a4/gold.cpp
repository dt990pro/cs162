#include "gold.h"

gold::gold() : event()
{
	set_name();
}

gold::~gold(){}

void gold::set_name()
{
	name = 'G';
}

void gold::percepts()
{
	cout << "You see a glimmer nearby." << endl;
}

void gold::display_percepts()
{
	percepts();
}