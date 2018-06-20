#include "animal.h"

animal::animal(){}

animal::animal(string str)
{
	set_name(str);
}

animal::~animal(){}

void animal::set_name(string str)
{
	name = str;
}

string animal::get_name()
{
	return name;
}