#include "penguin.h"

penguin::penguin() :animal()
{
	cost = 1000;
}

penguin::~penguin(){}

void penguin::set_age(int n)
{
	age = n;
}

int penguin::get_age()
{
	return age;
}