#include "tiger.h"

tiger::tiger() :animal()
{
	cost = 10000;
}

tiger::~tiger(){}

void tiger::set_age(int n)
{
	age = n;
}

int tiger::get_age()
{
	return age;
}

void tiger::set_bonus(float n)
{
	bonus = n;
}

float tiger::get_bonus()
{
	return bonus;
}