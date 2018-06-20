#include "pbear.h"

polar_bear::polar_bear() :animal()
{
	cost = 5000;
}

polar_bear::~polar_bear(){}

void polar_bear::set_age(int n)
{
	age = n;
}

int polar_bear::get_age()
{
	return age;
}