#include "bat.h"

bat::bat() : event()
{
	set_name();
}

bat::~bat(){}

void bat::set_name()
{
	name = 'B';
}

void bat::percepts()
{
	cout << "You hear wings flapping." << endl;
}

void bat::display_percepts()
{
	percepts();
}