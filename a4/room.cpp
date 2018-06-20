#include "room.h"

room::room()
{
	name = '*';
}

room::~room(){}

void room::set_p(int x, int y)
{
	px = x;
	py = y;
}

char room::get_name()
{
	return name;
}

int room::check_position(int x, int y)
{
	if (px == x && py == y) return 1;
	else return 0;
}

void room::display_percepts(){}